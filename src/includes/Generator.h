#pragma once

#include "Pixel.h"
#include "image.h"

#include <vector>
#include <string>
#include <fstream>
#include <string.h>

class Generator
{
public:
    Generator(const char *filename, Image image);

private:
    int getPixelIntensity(Pixel p);
    char getPixelValue(int intensity);

private:
    std::vector<std::string> characters;
    std::vector<Pixel> pixels;

private:
    const int MAX_PIXEL_VALUE = 255 * 4; // SUM OF ALL VALUES: R - 255, G - 255, B - 255, A - 255 -> 255 * 4

    const int CHARACTERS_COUNT = 8;                                                                     // THE NUMBER OF CHARACTERS USED FOR THE ART
    const char *CHARACTERS = " .'`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0Zmwqpdbkhao*#MW&8%B@$"; // CHARACTERS FOR ASCII ART
};