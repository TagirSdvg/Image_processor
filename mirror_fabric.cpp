#include "mirror_fabric.h"
#include "../filters/mirror.h"
#include "../exceptions.h"

MirrorFabric::MirrorFabric() {
}
std::shared_ptr<BaseFilter> MirrorFabric::Create(const std::vector<std::string>& input_params) {
    if (size(input_params) != 0) {
        throw FilterException("not enough params");
    }
    return std::make_shared<Mirror>();
}
