#include "sharpening_fabric.h"
#include "../filters/sharpening.h"
#include "../exceptions.h"

SharpeningFabric::SharpeningFabric() {
}

std::shared_ptr<BaseFilter> SharpeningFabric::Create(const std::vector<std::string>& input_params) {
    if (size(input_params) != 0) {
        throw FilterException("not enough params");
    }
    return std::make_shared<Sharpening>();
}
