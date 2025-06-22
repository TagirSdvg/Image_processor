#include "grayscale.h"
#include "../image.h"

const double RAD = 0.299;
const double GREEN = 0.587;
const double BLUE = 0.114;

void Grayscale::Apply(Image& image) {
    for (size_t y = 0; y < image.Height(); ++y) {
        for (size_t x = 0; x < image.Width(); ++x) {
            Pixel pixel = image.GetPixel(x, y);
            double new_colour = pixel.red * RAD + pixel.green * GREEN + pixel.blue * BLUE;
            pixel.red = new_colour;
            pixel.green = new_colour;
            pixel.blue = new_colour;
            image.SetPixel(x, y, pixel);
        }
    }
}
