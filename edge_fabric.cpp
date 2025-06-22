#include "edge_fabric.h"
#include "../filters/edge.h"
#include "../exceptions.h"

EdgeFabric::EdgeFabric() {
}

std::shared_ptr<BaseFilter> EdgeFabric::Create(const std::vector<std::string>& input_params) {
    if (input_params.size() != 1) {
        throw FilterException("not enough params");
    }
    double threshold = std::stod(input_params[0]);
    return std::make_shared<Edge>(threshold);
}
