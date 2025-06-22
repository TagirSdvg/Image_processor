#pragma once

#include <memory>
#include <vector>
#include <string>
#include "../filters/base_filter.h"
#include "base_fabric.h"

class SharpeningFabric : public BaseFabric {
public:
    std::shared_ptr<BaseFilter> Create(const std::vector<std::string>& input_params) override;
    SharpeningFabric();
    virtual ~SharpeningFabric() {
    }
};
