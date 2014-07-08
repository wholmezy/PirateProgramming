/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }
	
    // remember filenames
    int changeSize = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];
    
    
    // ensure proper usage.
    


    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }
    
    
   	if(changeSize > 100 || changeSize <= 1){
    	printf("Can only resize less than 100 and more than 1.\n");
    	return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    //Save current header from document being copied.
    BITMAPINFOHEADER bi2 = bi;
    //BITMAPFILEHEADER bf2 = bf;
    //Changes the header sizes
    bi.biWidth = bi.biWidth * changeSize;
    bi.biHeight = bi.biHeight * changeSize;
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int oneLine = (3 * bi.biWidth) + padding;
	bi.biSizeImage = oneLine * bi.biWidth;
	bf.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + bi.biSizeImage;
	
	//bi.biWidth + bi.biHeight + padding;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
	
    // iterate over infile's scanlines
    for (int i = 0; i < bi2.biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi2.biWidth; j++){
        
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile
			for(int n = changeSize; n >= 0; n--){
            	fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        	}
       	}

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

       	// then add it back (to demonstrate how)
       	for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
