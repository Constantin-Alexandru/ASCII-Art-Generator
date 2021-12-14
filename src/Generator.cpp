#include "./includes/Generator.h"

Generator::Generator(const char *filename, Image image)
{
    std::ofstream out(filename);

    pixels.resize(image.w * image.h);
    characters.resize(pixels.size());

    for (int i = 0; i < image.w * image.h * image.channels; i += 4)
    {
        pixels[i / 4] = Pixel(image.data[i], image.data[i + 1], image.data[i + 2], image.data[i + 3]);
    }

    for (int i = 0; i < characters.size(); i++)
    {
        characters[i] = getPixelValue(getPixelIntensity(pixels[i]));
    }

    for (int i = 0; i < characters.size(); i++)
    {
        out << characters[i];
        if (i % image.w == 0 && i != 0)
        {
            out << '\n';
        }
    }

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