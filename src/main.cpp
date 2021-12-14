#include "./includes/image.h"
#include "./includes/Generator.h"

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        Image img(argv[i]);
        std::string txt(argv[i]);

        txt += ".txt";

        Generator gen(txt.c_str(), img);
    }

    return 0;
}