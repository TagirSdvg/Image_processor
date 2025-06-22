#include "negative_fabric.h"
#include "../filters/negative.h"
#include "../exceptions.h"

NegativeFabric::NegativeFabric() {
}
std::shared_ptr<BaseFilter> NegativeFabric::Create(const std::vector<std::string>& input_params) {
    if (size(input_params) != 0) {
        throw FilterException("not enough params");
    }
    return std::make_shared<Negative>();
}
