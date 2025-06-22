#include "edge.h"
#include "../image.h"

#include <cmath>
#include <algorithm>

const double FOUR = 4.0;
const double MATRIX[3][3] = {{0.0, -1.0, 0.0}, {-1.0, FOUR, -1.0}, {0.0, -1.0, 0.0}};

const double RAD = 0.299;
const double GREEN = 0.587;
const double BLUE = 0.114;

void Edge::Apply(Image& image) {
    Image image_copy = image;
    for (size_t y = 0; y < image.Height(); ++y) {
        for (size_t x = 0; x < image.Width(); ++x) {
            Pixel pixel = image_copy.GetPixel(x, y);
            double red = pixel.red;
            double green = pixel.green;
            double blue = pixel.blue;
            pixel.red = red * RAD + green * GREEN + blue * BLUE;
            pixel.green = red * RAD + green * GREEN + blue * BLUE;
            pixel.blue = red * RAD + green * GREEN + blue * BLUE;
            image_copy.SetPixel(x, y, pixel);
        }
    }
    const int width = static_cast<int>(image_copy.Width());
    const int height = static_cast<int>(image_copy.Height());
    std::vector<std::vector<Pixel>> new_masa;
    new_masa.resize(height);
    for (size_t y = 0; y < height; ++y) {
        new_masa[y].resize(width);
    }
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            double new_red = 0.0;
            double new_green = 0.0;
            double new_blue = 0.0;

            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    int par1 = x + dx;
                    int par2 = y + dy;
                    if (par1 < 0) {
                        par1 = 0;
                    }
                    if (par2 < 0) {
                        par2 = 0;
                    }
                    if (par2 + 1 > height) {
                        par2 = height - 1;
                    }
                    if (par1 + 1 > width) {
                        par1 = width - 1;
                    }
                    Pixel pixel = image_copy.GetPixel(par1, par2);
                    new_red += MATRIX[dy + 1][dx + 1] * pixel.red;
                    new_green += MATRIX[dy + 1][dx + 1] * pixel.green;
                    new_blue += MATRIX[dy + 1][dx + 1] * pixel.blue;
                }
            }

            new_red = std::clamp(new_red, 0.0, 1.0);
            new_green = std::clamp(new_green, 0.0, 1.0);
            new_blue = std::clamp(new_blue, 0.0, 1.0);

            if (new_red > treshold_) {
                new_red = 1.0;
            }
            if (new_red < treshold_) {
                new_red = 0.0;
            }
            if (new_green > treshold_) {
                new_green = 1.0;
            }
            if (new_green < treshold_) {
                new_green = 0.0;
            }
            if (new_blue > treshold_) {
                new_blue = 1.0;
            }
            if (new_blue < treshold_) {
                new_blue = 0.0;
            }
            Pixel new_pixel = {new_red, new_green, new_blue};
            new_masa[y][x] = new_pixel;
        }
    }
    image.SetPixels(new_masa);
}
