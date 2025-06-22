#pragma once

#include <memory>
#include <vector>
#include <string>
#include "base_filter.h"

class Mirror : public BaseFilter {
public:
    virtual ~Mirror() {
    }
    void Apply(Image& image) override;
};
