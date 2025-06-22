#include "crop.h"
#include "../image.h"
#include <algorithm>

Crop::Crop(int width, int height) : width_(width), height_(height) {
}

void Crop::Apply(Image& image) {
    int new_width = static_cast<int>(std::min(width_, image.Width()));
    int new_height = static_cast<int>(std::min(height_, image.Height()));

    Image new_image(new_width, new_height);
    for (int y = 0; y < new_height; ++y) {
        for (int x = 0; x < new_width; ++x) {
            Pixel pixel = image.GetPixel(x, y);
            new_image.SetPixel(x, y, pixel);
        }
    }
    image = new_image;
    image.SetWidth(new_image.Width());
    image.SetHeight(new_image.Height());
}
