#pragma once

#include "base_filter.h"

class Crop : public BaseFilter {

public:
    Crop(int width, int height);
    virtual ~Crop() {
    }

    void Apply(Image& image) override;

private:
    size_t width_;
    size_t height_;
};
