#pragma once

#include <memory>
#include <vector>
#include <string>
#include "base_filter.h"

class Grayscale : public BaseFilter {
public:
    virtual ~Grayscale() {
    }
    void Apply(Image& image) override;
};
