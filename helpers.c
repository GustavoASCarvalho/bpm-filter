#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int media = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = media;
            image[i][j].rgbtGreen = media;
            image[i][j].rgbtRed = media;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE *tmp = malloc(sizeof(RGBTRIPLE));
    for(int i = 0; i < height; i++) {
        int k = width - 1;
        for(int j = 0; j != k && j != k+1; j++, k--) {
            *tmp = image[i][j];
            image[i][j] = image[i][k];
            image[i][k] = *tmp;
        }
    }
    free(tmp);
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copia[height][width];
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int somaVerde = 0;
            int somaVermelho = 0;
            int somaAzul = 0;
            float qtd = 0;
            for(int k = i-1; k <= i+1; k++){
                for(int l = j-1; l <= j+1; l++){
                    if (k >= 0 && k < height && l >= 0 && l < width){
                        qtd++;
                        somaVerde += image[k][l].rgbtGreen;
                        somaVermelho += image[k][l].rgbtRed;
                        somaAzul += image[k][l].rgbtBlue;
                    }
                }
            }
            qtd = (float)qtd;
            copia[i][j].rgbtGreen = round(somaVerde / qtd);
            copia[i][j].rgbtRed = round(somaVermelho / qtd);
            copia[i][j].rgbtBlue = round(somaAzul / qtd);
        }
    }
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            image[i][j] = copia[i][j];
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int gx[3][3] = {{-1, 0, 1},
                    {-2, 0, 2},
                    {-1, 0, 1}};

    int gy[3][3] = {{-1, -2, -1},
                    { 0,  0,  0},
                    { 1,  2,  1}};

    RGBTRIPLE copia[height][width];

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int somaVerdeGX = 0;
            int somaVermelhoGX = 0;
            int somaAzulGX = 0;
            int somaVerdeGY = 0;
            int somaVermelhoGY = 0;
            int somaAzulGY = 0;
            for(int k = i-1, contK = 0; k <= i+1; k++, contK++){
                for(int l = j-1, contL = 0; l <= j+1; l++, contL++){
                    if (k >= 0 && k < height && l >= 0 && l < width){
                        somaVerdeGX += image[k][l].rgbtGreen * gx[contK][contL];
                        somaVermelhoGX += image[k][l].rgbtRed * gx[contK][contL];
                        somaAzulGX += image[k][l].rgbtBlue * gx[contK][contL];
                        somaVerdeGY += image[k][l].rgbtGreen * gy[contK][contL];
                        somaVermelhoGY += image[k][l].rgbtRed * gy[contK][contL];
                        somaAzulGY += image[k][l].rgbtBlue * gy[contK][contL];
                    }
                }
            }
            int verde = round(sqrt(((somaVerdeGX * somaVerdeGX) + (somaVerdeGY * somaVerdeGY))));
            int vermelho = round(sqrt(((somaVermelhoGX * somaVermelhoGX) + (somaVermelhoGY * somaVermelhoGY))));
            int azul = round(sqrt(((somaAzulGX * somaAzulGX) + (somaAzulGY * somaAzulGY))));

            if(verde < 0) {
                verde = 0;
            }else if(verde > 255){
                verde = 255;
            }
            if(vermelho < 0) {
                vermelho = 0;
            }else if(vermelho > 255){
                vermelho = 255;
            }
            if(azul < 0) {
                azul = 0;
            }else if(azul > 255){
                azul = 255;
            }

            copia[i][j].rgbtGreen = verde;
            copia[i][j].rgbtRed = vermelho;
            copia[i][j].rgbtBlue = azul;
        }
    }
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            image[i][j] = copia[i][j];
    return;
}
