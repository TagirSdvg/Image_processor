#include "image.h"

void Image::SetPixel(size_t x, size_t y, Pixel pixel) {
    pixels_[y][x] = pixel;
};

Pixel Image::GetPixel(size_t x, size_t y) const {
    return pixels_[y][x];
};

size_t Image::Height() const {
    return height_;
};

size_t Image::Width() const {
    return width_;
};

Image::Image(size_t width_val, size_t height_val) : pixels_(height_val, std::vector<Pixel>(width_val)) {
    width_ = width_val;
    height_ = height_val;
}

void Image::SetPixels(std::vector<std::vector<Pixel>> parametr) {
    pixels_ = parametr;
}
