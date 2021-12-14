#pragma once

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <iostream>

enum class ImageType
{
    PNG,
    JPG,
    BMP,
    TGA
};

class Image
{
public:
    uint8_t *data = NULL;
    size_t size = 0;
    int w;
    int h;
    int channels;

    Image(const char *filename);
    Image(int w, int h, int channels);
    Image(const Image &img);
    ~Image();

    bool read(const char *filename);
    bool write(const char *filename);

    friend std::ostream &operator<<(std::ostream &out, const Image &img);

private:
    ImageType getFileType(const char *filename);
};