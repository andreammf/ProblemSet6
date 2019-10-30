#include <stdio.h>
#include <stdlib.h>

const int WIDTH = 600;
const int HEIGHT = 600;
const int RGB = 3;

int getIndex(int w, int h, int d);
void flipHorizontal(unsigned char image[WIDTH][HEIGHT][RGB]);

int main(){
  unsigned char image = malloc(sizeof(unsigned char) * RGB * WIDTH * HEIGHT);
  unsigned char ctmp;
  int x,y,i;
  
  FILE *fp;
  if((fp=fopen("Gradient.ppm","r"))==NULL){
    printf("File does not exist or corrupted.\n");
    return 1;
  }
    
    fscanf(fp,"P3\n600 600\n255\n"); //Skip reading the header file
    
    //Get colors for each pixel
    unsigned int color;
    for(int x = 0; x < WIDTH; x++){
        for(int y = 0; y < HEIGHT; y++){
            for(int rgb = 0; rgb < RGB; rgb++){
                fscanf(fp, "%u", &color);
                image[x][y][rgb] = color;
            }
        }
    }
    fclose(fp);

    

    flipHorizontal(image);

  return 0;
}

void flipHorizontal(unsigned char *image){
    FILE *reversed = fopen("reversedGradient.ppm", "w");
    fprintf(reversed, "P3\n600 600\n255\n");

    for(int x = WIDTH-1; x > 0; x--){
        for(int y = 0; y < HEIGHT; y++){
            for(int rgb = 0; rgb < RGB; rgb++){
                fprintf(reversed, "%i ", image[]);
            }
        }
    }

    fclose(reversed);
}

int getIndex(int w, int h, int d){
   return WIDTH * RGB * h + RGB * w + d;
