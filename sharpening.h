#pragma once

#include "base_filter.h"

class Sharpening : public BaseFilter {
public:
    virtual ~Sharpening() {
    }
    void Apply(Image& image) override;
};
