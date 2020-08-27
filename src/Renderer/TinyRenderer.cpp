#include <iostream>
#include <string>
#include <mutex>
#include <sstream>
#include <fstream>

#include "Logger.h"
#include "tgaimage.h"

Logger::Log LogObject("TinyRenderer.log");

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

int main()
{
    std::cout << "Chugga chugga choo choo!\n";
    LogObject.Write(Logger::Level::INFO,
                    "Testing: ",
                    123);

    TGAImage image(100, 100, TGAImage::RGB);
    image.set(52, 41, red);
    image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
    image.write_tga_file("output.tga");

    return 0;
}
