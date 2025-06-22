#pragma once

#include "base_fabric.h"

class CropFabric : public BaseFabric {
public:
    CropFabric();
    virtual ~CropFabric() {
    }
    std::shared_ptr<BaseFilter> Create(const std::vector<std::string>& input_params) override;
};
