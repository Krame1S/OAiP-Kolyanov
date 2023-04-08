#include <stdio.h>
#include <stdlib.h>
#include "conversion.h"
#include "output.h"



int checkBMP(BMPHeader bmph, BitNapInfoHeader infh) {

    //проверяем, что файл bmp
    if (bmph.fileType != 0x4D42) {
        printf("This is not BMP!");
        return 1;
    }

    //проверяем, что битность - 24
    if (infh.bitsPerPixel != 24) {
        printf("This is not BMP 24-bit!");
        return 1;
    }
    return 0;
}

void convertToNegativ(BMPHeader bhdr, BitNapInfoHeader dhdr, FILE* origBMPFile) {

    Pixel pixelIn;
    Pixel pixelOut;
    FILE* negBMPFile = fopen("samples\/negativ.bmp", "wb");
    if (negBMPFile == NULL) {
        throwError();
    }
 
    fwrite(&bhdr, sizeof(BMPHeader), 1, negBMPFile);
    fwrite(&dhdr, sizeof(BitNapInfoHeader), 1, negBMPFile);
    fseek(negBMPFile, bhdr.pixelOffset, SEEK_SET);
    fseek(origBMPFile, bhdr.pixelOffset, SEEK_SET);
    for (unsigned int i = 0; i < dhdr.BMHeight; i++) {
        for (unsigned int j = 0; j < dhdr.BMWidth; j++) {
            fread(&pixelIn, sizeof(Pixel), 1, origBMPFile);
            pixelOut.pixelBlue = 255 - pixelIn.pixelBlue;
            pixelOut.pixelGreen = 255 - pixelIn.pixelGreen;
            pixelOut.pixelRed = 255 - pixelIn.pixelRed;
            fwrite(&pixelOut, sizeof(Pixel), 1, negBMPFile);
        }
    }
    fclose(negBMPFile);
}

void convertToGreyScale(BMPHeader bhdr, BitNapInfoHeader dhdr, FILE* origBMPFile) {

    Pixel pixelIn;
    Pixel pixelOut;
    unsigned char grey;
    FILE* greyScaleBMPFile = fopen("samples\/grey.bmp", "wb");
    if (greyScaleBMPFile == NULL) {
        perror("Error occured while opening");
        return 1;
    }

    fwrite(&bhdr, sizeof(BMPHeader), 1, greyScaleBMPFile);
    fwrite(&dhdr, sizeof(BitNapInfoHeader), 1, greyScaleBMPFile);
    fseek(greyScaleBMPFile, bhdr.pixelOffset, SEEK_SET);
    fseek(origBMPFile, bhdr.pixelOffset, SEEK_SET);
    
    for (unsigned int i = 0; i < dhdr.BMHeight; i++) {
        for (unsigned int j = 0; j < dhdr.BMWidth; j++) {
            fread(&pixelIn, sizeof(Pixel), 1, origBMPFile);
            grey = pixelIn.pixelBlue * 0.114 + pixelIn.pixelGreen * 0.587 + pixelIn.pixelRed * 0.299;
            pixelOut.pixelBlue = grey;
            pixelOut.pixelGreen = grey;
            pixelOut.pixelRed = grey;
            fwrite(&pixelOut, sizeof(Pixel), 1, greyScaleBMPFile);
        }
    }

    fclose(greyScaleBMPFile);
}