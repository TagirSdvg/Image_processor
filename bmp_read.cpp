#include "bmp_read.h"
#include "exceptions.h"
#include <vector>
#include <stdexcept>
#include <cstdint>
#include <cstring>

const int TWENTYFOUR = 24;
const int SOMENUMBER = 0x4D42;
const size_t THAT = 255;

Image BMPRead(const std::string& file_path) {
    BinaryReader reader(file_path);

    BITMAPFILEHEADER file_header{};
    BITMAPINFOHEADER info_header{};

    reader.Read(reinterpret_cast<char*>(&file_header), sizeof(file_header));
    reader.Read(reinterpret_cast<char*>(&info_header), sizeof(info_header));

    if (info_header.biBitCount != TWENTYFOUR) {
        throw BMPException("incorrect input image");
    }

    const uint32_t width = info_header.biWidth;
    const uint32_t height = abs(info_header.biHeight);
    Image image(width, height);

    const size_t row_padding = (4 - (width * 3) % 4) % 4;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            uint8_t b = THAT;
            uint8_t g = THAT;
            uint8_t r = THAT;
            reader >> b >> g >> r;

            const size_t image_y = info_header.biHeight > 0 ? height - y - 1 : y;
            image.SetPixel(x, image_y,
                           {static_cast<float>(r) / THAT, static_cast<float>(g) / THAT, static_cast<float>(b) / THAT});
        }
        uint8_t padding_byte = 0;
        for (int i = 0; i < row_padding; ++i) {
            reader >> padding_byte;
        }
    }
    return image;
}

void BMPWrite(const Image& image, const std::string& file_path) {
    BinaryWriter writer(file_path);

    const uint32_t width = image.Width();
    const uint32_t height = image.Height();
    const size_t row_padding = (4 - (width * 3) % 4) % 4;

    BITMAPFILEHEADER file_header{};
    BITMAPINFOHEADER info_header{};

    file_header.bfType = SOMENUMBER;
    file_header.bfOffBits = sizeof(file_header) + sizeof(info_header);
    file_header.bfSize = file_header.bfOffBits + (width * 3 + row_padding) * height;

    info_header.biSize = sizeof(info_header);
    info_header.biWidth = static_cast<int32_t>(width);
    info_header.biHeight = static_cast<int32_t>(height);
    info_header.biPlanes = 1;
    info_header.biBitCount = TWENTYFOUR;
    info_header.biCompression = 0;
    info_header.biSizeImage = (width * 3 + row_padding) * height;

    writer.Write(reinterpret_cast<const char*>(&file_header), sizeof(file_header));
    writer.Write(reinterpret_cast<const char*>(&info_header), sizeof(info_header));

    for (int y = static_cast<int>(height) - 1; y >= 0; --y) {
        for (int x = 0; x < width; ++x) {
            const auto& pixel = image.GetPixel(x, y);
            writer << static_cast<uint8_t>(pixel.blue * THAT) << static_cast<uint8_t>(pixel.green * THAT)
                   << static_cast<uint8_t>(pixel.red * THAT);
        }
        for (size_t i = 0; i < row_padding; ++i) {
            writer << static_cast<uint8_t>(0);
        }
    }
}
