#ifndef MANDELBROT_H
#define MANDELBROT_H

#include "image.h"   // write_pixel
#include <complex.h> // complex, cabs

int mandelbrot(int height, int width, unsigned char pixels[], int max_iter);

#endif