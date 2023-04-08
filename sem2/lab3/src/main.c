#include <stdio.h>
#include <stdlib.h>
#include "conversion.h"
#include "output.h"
#define FILE_NAME_SIZE 255

//#define FROM_COMMAND_LINE
#ifdef FROM_COMMAND_LINE 

int main(int argc, char* argv[]){

    BMPHeader bhdr;
    BitNapInfoHeader dhdr;
    Pixel pixelIn;
    Pixel pixelOut;

    if (argc < 2) {
        printf("Invalid number of arguments! ");
        throwError();
    }

    FILE* origBMPFile = fopen(argv[1], "rb");
    if (!origBMPFile) {
        printf("There is no such file in a directory ");
        throwError();
    }
    //Чтение из заголовка файла BMPHeader
    fread(&bhdr, sizeof(BMPHeader), 1, origBMPFile);
    //Чтение из заголовка файла BitNapInfoHeader
    fread(&dhdr, sizeof(BitNapInfoHeader), 1, origBMPFile);

    //проверяем, что файл bmp
    if (checkBMP(bhdr, dhdr) != 0) {
        fclose(origBMPFile);
        throwError();
    }

    //конвертация в негатив
    convertToNegativ(bhdr, dhdr, origBMPFile);

    //конвертация в градации серого
    convertToGreyScale(bhdr, dhdr, origBMPFile);

    fclose(origBMPFile);

    printf("Success! You can find them files in the samples folder!\n");

    return 0;
}

#else //!FROM_COMMAND_LINE

int main(int argc, char* argv[])
{
    char fileName[FILE_NAME_SIZE];
    BMPHeader bhdr;
    BitNapInfoHeader dhdr;
    Pixel pixelIn;
    Pixel pixelOut;

    printf("Enter file name:\n");
    scanf("%s", fileName);

    FILE* origBMPFile = fopen(fileName, "rb");
    if (origBMPFile == NULL) {
        throwError();
    }

    //Чтение из заголовка файла BMPHeader
    fread(&bhdr, sizeof(BMPHeader), 1, origBMPFile);
    //Чтение из заголовка файла BitNapInfoHeader
    fread(&dhdr, sizeof(BitNapInfoHeader), 1, origBMPFile);

    //проверяем, что файл bmp
    if (checkBMP(bhdr, dhdr) != 0) {
        fclose(origBMPFile);
        throwError();
    }

    //конвертация в негатив
    convertToNegativ(bhdr, dhdr, origBMPFile);
   
    //конвертация в градации серого
    convertToGreyScale(bhdr, dhdr, origBMPFile);
    
    fclose(origBMPFile);

     printf("Success! You can find them files in the samples folder!\n");
    
    return 0;
}

#endif //FROM_COMMAND_LINE