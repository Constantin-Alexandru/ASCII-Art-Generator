#include "./includes/Generator.h"

Generator::Generator(const char *filename, Image image)
{
    std::ofstream out(filename);

    printf("GENERATING %s - Width: %d | Height: %d | Channels: %d\n", filename, image.w, image.h, image.channels);

    int channels = image.channels;

    this->MAX_PIXEL_VALUE = 255 * channels;

    for (int i = 0; i < image.w * image.h * channels; i += channels)
    {
        if (channels == 1)
        {
            pixels.push_back(Pixel(image.data[i]));
        }
        else if (channels == 2)
        {
            pixels.push_back(Pixel(image.data[i], image.data[i + 1]));
        }
        else if (channels == 3)
        {
            pixels.push_back(Pixel(image.data[i], image.data[i + 1], image.data[i + 2]));
        }
        else if (channels == 4)
        {
            pixels.push_back(Pixel(image.data[i], image.data[i + 1], image.data[i + 2], image.data[i + 3]));
        }
    }

    for (int i = 0; i < pixels.size(); i++)
    {
        characters.push_back(getPixelValue(getPixelIntensity(pixels[i])));
    }

    for (int i = 0; i < characters.size(); i++)
    {
        out << characters[i];
        if (i % image.w == 0 && i != 0)
        {
            out << '\n';
        }
    }

    printf("FINISHED GENERATING %s\n", filename);

    out.close();
}

int Generator::getPixelIntensity(Pixel p)
{
    int sum = p.r + p.g + p.b + p.a;

    return (int)(((double)sum / MAX_PIXEL_VALUE) * CHARACTERS_COUNT);
}

char Generator::getPixelValue(int intensity)
{
    return CHARACTERS[intensity];
}