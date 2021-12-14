#include "./includes/image.h"

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "./includes/stb_image.h"
#include "./includes/stb_image_write.h"

Image::Image(const char *filename)
{
    if (read(filename))
    {
        printf("Successfully read %s\n", filename);
        size = w * h * channels;
    }
    else
    {
        printf("Failed to read %s\n", filename);
    }
}

Image::Image(int w, int h, int channels) : w(w), h(h), channels(channels)
{
    size = w * h * channels;
    data = new uint8_t[size];
}

Image::Image(const Image &img) : Image(img.w, img.h, img.channels)
{
    memcpy(data, img.data, size);
}

Image::~Image()
{
    stbi_image_free(data);
}

bool Image::read(const char *filename)
{
    data = stbi_load(filename, &w, &h, &channels, 4);
    return data != NULL;
}

bool Image::write(const char *filename)
{
    ImageType type = getFileType(filename);
    int success = 0;

    switch (type)
    {
    case ImageType::PNG:
        success = stbi_write_png(filename, w, h, channels, data, w * channels);
        break;
    case ImageType::JPG:
        success = stbi_write_jpg(filename, w, h, channels, data, 100);
        break;
    case ImageType::BMP:
        success = stbi_write_bmp(filename, w, h, channels, data);
        break;
    case ImageType::TGA:
        success = stbi_write_tga(filename, w, h, channels, data);
        break;
    }

    return success != 0;
}

ImageType Image::getFileType(const char *filename)
{
    const char *ext = strrchr(filename, '.');
    if (ext != nullptr)
    {
        if (strcmp(ext, ".png") == 0)
        {
            return ImageType::PNG;
        }
        else if (strcmp(ext, ".jpg") == 0)
        {
            return ImageType::JPG;
        }
        else if (strcmp(ext, ".bmp") == 0)
        {
            return ImageType::BMP;
        }
        if (strcmp(ext, ".tga") == 0)
        {
            return ImageType::TGA;
        }
    }

    return ImageType::PNG;
}
