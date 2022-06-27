#include "image.h"      // clear_image, write_image,
#include "mandelbrot.h" // mandelbrot,

#include <stdint.h> // uint8_t,
#include <stdio.h>
#include <stdlib.h> // exit,

int main(void) {
  uint32_t height, width;
  uint8_t max_iter;
  char *filename;

  height = 1000;
  width = 1000;
  max_iter = 255;
  filename = "mandelbrot.ppm";

  uint8_t *pixels = malloc(height * width * sizeof(uint8_t));
  clear_image(height, width, pixels);

  if (mandelbrot(height, width, pixels, max_iter) != 0) {
    free(pixels);
    exit(1);
  }

  if (write_image(height, width, pixels, filename) != 0) {
    free(pixels);
    exit(1);
  }

  printf("File written successfully\n");
}