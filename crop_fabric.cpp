#include "crop_fabric.h"
#include "../filters/crop.h"
#include "../exceptions.h"

CropFabric::CropFabric() {
}

std::shared_ptr<BaseFilter> CropFabric::Create(const std::vector<std::string>& input_params) {
    if (input_params.size() != 2) {
        throw FilterException("Not enough paramrs");
    }

    int width = std::stoi(input_params[0]);
    int height = std::stoi(input_params[1]);

    return std::make_shared<Crop>(width, height);
}
