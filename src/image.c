#include "image.h"

/**
 *  clear the canvas, i.e. convert all pixels to white
 *
 */
void clear_image(int height, int width, unsigned char pixels[]) {
  int p;
  for (p = 0; p < height * width; ++p)
    pixels[p] = 255;
}

/**
 *  write the pixels data to the image file (ppm)
 *
 */
int write_image(int height, int width, unsigned char pixels[], char *path) {
  int p;
  unsigned char c;
  FILE *fptr;

  fptr = fopen(path, "w");
  if (fptr == NULL) {
    fprintf(stderr, "Failed to open output file\n");
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
int write_pixel(int height, int width, int x, int y, unsigned char pixels[],
                unsigned char color) {
  int index;
  if (y > height || x > width) {
    fprintf(stderr, "Write pixel out of range: (%d, %d)\n", x, y);
    return 1;
  }

  index = (y * width) + x;
  pixels[index] = color;

  return 0;
}