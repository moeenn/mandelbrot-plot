#include "mandelbrot.h"

int mandelbrot(int height, int width, unsigned char pixels[], int max_iter) {
  int x, y, i;
  double re, im;
  double complex z, c;

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
            return 1;
          }
          break;
        }
      }
    }
  }

  return 0;
}