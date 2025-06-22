#include "negative.h"
#include "../image.h"

void Negative::Apply(Image& image) {
    for (size_t y = 0; y < image.Height(); ++y) {
        for (size_t x = 0; x < image.Width(); ++x) {
            Pixel pixel = image.GetPixel(x, y);
            pixel.red = 1 - pixel.red;
            pixel.green = 1 - pixel.green;
            pixel.blue = 1 - pixel.blue;
            image.SetPixel(x, y, pixel);
        }
    }
}
