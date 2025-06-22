#pragma once

#include <memory>
#include <vector>
#include <string>
#include "base_filter.h"

class Negative : public BaseFilter {
public:
    virtual ~Negative() {
    }
    void Apply(Image& image) override;
};
