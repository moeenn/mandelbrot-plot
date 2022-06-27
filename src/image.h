#ifndef IMAGE_H
#define IMAGE_H

#include <stdint.h> // uint8_t
#include <stdio.h>

void clear_image(int height, int width, uint8_t pixels[]);
int write_image(int height, int width, uint8_t pixels[], char *path);
int write_pixel(int height, int width, int x, int y, uint8_t pixels[],
                uint8_t color);

#endif