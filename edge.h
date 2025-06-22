#pragma once

#include "base_filter.h"

class Edge : public BaseFilter {
public:
    explicit Edge(double treshold) : treshold_(treshold) {
    }
    virtual ~Edge() {
    }
    void Apply(Image& image) override;

private:
    double treshold_;
};
