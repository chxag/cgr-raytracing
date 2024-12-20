#include "ppmWriter.h"
#include <iostream>
#include <fstream>

PPMWriter::PPMWriter(int width, int height, const std::vector<unsigned char>& backgrounddata)
    : width(width), height(height), backgrounddata(backgrounddata)
{
    pixeldata.resize(width * height * 3);
    for (int i = 0; i < width * height; ++i)
    {
        pixeldata[i * 3] = backgrounddata[0];
        pixeldata[i * 3 + 1] = backgrounddata[1];
        pixeldata[i * 3 + 2] = backgrounddata[2];
    }
}

void PPMWriter::getPixelData(int x, int y, const std::vector<unsigned char>& colordata)
{
    int index = (y * width + x) * 3;
    pixeldata[index] = colordata[0];
    pixeldata[index + 1] = colordata[1];
    pixeldata[index + 2] = colordata[2];
}

void PPMWriter::writePPM(const std::string& filename) const {
    std::ofstream file(filename, std::ios::binary);
    if(file.is_open()) {
        file << "P6\n" << width << " " << height << "\n255\n";
        file.write(reinterpret_cast<const char*>(pixeldata.data()), pixeldata.size());
        file.close();
    } else {
        std::cerr << "Error: Could not open file " << filename << " for writing." << std::endl;
    }
}