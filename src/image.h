#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>

void clear_image(int height, int width, unsigned char pixels[]);
int write_image(int height, int width, unsigned char pixels[], char *path);
int write_pixel(int height, int width, int x, int y, unsigned char pixels[],
                unsigned char color);

#endif