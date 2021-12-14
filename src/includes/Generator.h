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
    std::vector<char> characters;
    std::vector<Pixel> pixels;

private:
    int MAX_PIXEL_VALUE; // SUM OF ALL VALUES: R - 255, G - 255, B - 255, A - 255

    const int CHARACTERS_COUNT = 71;                                                                     // THE NUMBER OF CHARACTERS USED FOR THE ART
    const char *CHARACTERS = " .'`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$"; // CHARACTERS FOR ASCII ART
    // const char *CHARACTERS = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]S?-_+~<>i!lI;:,\"^`'. "; // CHARACTERS FOR ASCII ART

    // const int CHARACTERS_COUNT = 8;
    // const char *CHARACTERS = " .'`^\",:";
    // const char *CHARACTERS = ":,\"^`'. ";

    // const int CHARACTERS_COUNT = 10;
    // const char *CHARACTERS = "@%#*+=-:. ";
    // const char *CHARACTERS = " .:-=+*#%@";
};