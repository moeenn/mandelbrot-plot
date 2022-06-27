#ifndef MANDELBROT_H
#define MANDELBROT_H

#include "image.h"   // write_pixel
#include <complex.h> // complex, cabs
#include <stdint.h>  // uint8_t, 

int mandelbrot(int height, int width, uint8_t pixels[], uint8_t max_iter);

#endif