#include <assert.h>  // assert
#include <complex.h> // complex, cabs
#include <stdio.h>
#include <stdlib.h> // exit,

#define uint8 unsigned char

/* function signatures */
void clear_image(int height, int width, uint8 pixels[]);
int write_image(int height, int width, uint8 pixels[], char *path);
int write_pixel(int height, int width, int x, int y, uint8 pixels[],
                uint8 color);

int main() {
  int height, width, x, y, max_iter, i;
  double re, im;
  double complex z, c;

  height = 1000;
  width = 1000;
  max_iter = 255;

  uint8 *pixels = malloc(height * width * sizeof(uint8));
  clear_image(height, width, pixels);

  for (y = 0; y < height; ++y) {
    im = (y - (height / 2.f)) / height * 2.5f;

    for (x = 0; x < width; ++x) {
      re = ((x - (width / 2.f)) / width * 2.5f) - 0.5f;
      z = re + im * I;
      c = z;

      for (i = 0; i < max_iter; ++i) {
        z = (z * z) + c;
        if (cabs(z) > 2.5f) {
          if (write_pixel(height, width, x, y, pixels, i) != 0) {
            free(pixels);
          }
          break;
        }
      }
    }
  }

  if (write_image(height, width, pixels, "./sample.ppm") == 1) {
    printf("Failed to open output file\n");
    free(pixels);
    exit(1);
  }

  printf("File written successfully\n");
}

/**
 *  clear the canvas, i.e. convert all pixels to white
 *
 */
void clear_image(int height, int width, uint8 pixels[]) {
  int p;
  for (p = 0; p < height * width; ++p)
    pixels[p] = 255;
}

/**
 *  write the pixels data to the image file (ppm)
 *
 */
int write_image(int height, int width, uint8 pixels[], char *path) {
  int p;
  unsigned char c;
  FILE *fptr;

  fptr = fopen(path, "w");
  if (fptr == NULL) {
    return 1;
  }

  /* insert header */
  fprintf(fptr, "P3\n%d %d\n%d\n", width, height, 255);

  for (p = 0; p < height * width; p++) {
    c = pixels[p];
    fprintf(fptr, "%d %d %d ", c, c, c);
  }

  fclose(fptr);
  return 0;
}

/**
 *  write single color, at (x, y) to the pixels array
 *
 */
int write_pixel(int height, int width, int x, int y, uint8 pixels[],
                uint8 color) {
  int index;
  if (y > height || x > width) {
    fprintf(stderr, "Write pixel out of range: (%d, %d)\n", x, y);
    return 1;
  }

  index = (y * width) + x;
  assert(index <= (height * width));
  pixels[index] = color;

  return 0;
}