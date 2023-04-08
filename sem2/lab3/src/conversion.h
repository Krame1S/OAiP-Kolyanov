#ifndef BMP_READER
#define BMP_READER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#pragma pack(push, 1)  //Необходимо для размещения элементов структуры в памяти НЕ кратно 4словам, а подряд

typedef  struct BMPHeader {
    unsigned short fileType;
    unsigned int fileSize;
    unsigned short unusedRezerved1;
    unsigned short unusedRezerved2;
    unsigned int pixelOffset;
} BMPHeader;

typedef struct BitNapInfoHeader {
    unsigned int headerSize;
    unsigned int BMWidth;
    unsigned int BMHeight;
    unsigned short Planes;
    unsigned short bitsPerPixel;
    unsigned int compressionMethod;
    unsigned int dataSize;
    unsigned int biXPelsPerMeter;
    unsigned int biYPelsPerMeter;
    unsigned int  colorsAmount;
    unsigned int  importantColors;
} BitNapInfoHeader;

typedef struct tagPixel {
    unsigned char    pixelBlue;
    unsigned char    pixelGreen;
    unsigned char    pixelRed;
} Pixel;

#pragma pack(pop)

void convertToNegativ(BMPHeader bhdr, BitNapInfoHeader dhdr, FILE* origBMPFile);
void convertToGreyScale(BMPHeader bhdr, BitNapInfoHeader dhdr, FILE* origBMPFile);
int checkBMP(BMPHeader bmph, BitNapInfoHeader infh);

#endif // BMP_READER