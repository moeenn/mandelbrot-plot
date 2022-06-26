#include "image.h"      // clear_image, write_image,
#include "mandelbrot.h" // mandelbrot,

#include <stdio.h>
#include <stdlib.h> // exit,

int main(void) {
  int height, width, max_iter;
  char *filename;

  height = 1000;
  width = 1000;
  max_iter = 255;
  filename = "mandelbrot.ppp\0";

  unsigned char *pixels = malloc(height * width * sizeof(unsigned char));
  clear_image(height, width, pixels);

  if (mandelbrot(height, width, pixels, max_iter) != 0) {
    free(pixels);
  }

  if (write_image(height, width, pixels, filename) != 0) {
    free(pixels);
    exit(1);
  }

  printf("File written successfully\n");
}