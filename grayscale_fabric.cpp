#include "grayscale_fabric.h"
#include "../filters/grayscale.h"
#include "../exceptions.h"

GrayscaleFabric::GrayscaleFabric() {
}
std::shared_ptr<BaseFilter> GrayscaleFabric::Create(const std::vector<std::string>& input_params) {
    if (size(input_params) != 0) {
        throw FilterException("a lot params");
    }
    return std::make_shared<Grayscale>();
}
