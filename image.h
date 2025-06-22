#pragma once

#include <vector>

struct Pixel {
    double red;
    double green;
    double blue;
};

class Image {
private:
    std::vector<std::vector<Pixel>> pixels_;
    size_t height_;
    size_t width_;

public:
    void SetPixel(size_t x, size_t y, Pixel pixel);

    Pixel GetPixel(size_t x, size_t y) const;
    size_t Height() const;
    size_t Width() const;
    void SetWidth(size_t width) {
        width_ = width;
    }
    void SetHeight(size_t height) {
        height_ = height;
    }
    Image(size_t height, size_t width);

    void SetPixels(std::vector<std::vector<Pixel>> parametr);
};
