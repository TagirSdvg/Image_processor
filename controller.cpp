#include "controller.h"
#include "exceptions.h"

std::vector<std::shared_ptr<BaseFilter>> CreateFilters(const std::vector<InputFilter>& input_filters) {
    std::vector<std::shared_ptr<BaseFilter>> filters;
    for (const auto& input_filter : input_filters) {

        if (FABRICS.find(input_filter.filter_name) == FABRICS.end()) {
            throw ControllerException("incorrect filter");
        }
        std::shared_ptr<BaseFabric> fabric = FABRICS.at(input_filter.filter_name);
        filters.push_back(fabric->Create(input_filter.filter_params));
    }
    return filters;
}

void ApplyFilters(const std::vector<std::shared_ptr<BaseFilter>>& filters, Image& image) {
    for (const auto& filter : filters) {
        filter->Apply(image);
    }
}
