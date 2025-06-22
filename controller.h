#pragma once

#include "fabrics/base_fabric.h"
#include "fabrics/crop_fabric.h"
#include "filters/base_filter.h"
#include "parser.h"
#include "filters/crop.h"
#include "fabrics/negative_fabric.h"
#include "filters/negative.h"
#include "fabrics/grayscale_fabric.h"
#include "filters/grayscale.h"
#include "fabrics/sharpening_fabric.h"
#include "filters/sharpening.h"
#include "fabrics/mirror_fabric.h"
#include "filters/mirror.h"
#include "fabrics/edge_fabric.h"
#include "filters/edge.h"

#include <memory>
#include <unordered_map>
#include <vector>

const std::unordered_map<std::string, std::shared_ptr<BaseFabric>> FABRICS = {
    {"crop", std::make_shared<CropFabric>()},        {"neg", std::make_shared<NegativeFabric>()},
    {"gs", std::make_shared<GrayscaleFabric>()},     {"mirror", std::make_shared<MirrorFabric>()},
    {"sharp", std::make_shared<SharpeningFabric>()}, {"edge", std::make_shared<EdgeFabric>()}};

std::vector<std::shared_ptr<BaseFilter>> CreateFilters(const std::vector<InputFilter>& input_filters);

void ApplyFilters(const std::vector<std::shared_ptr<BaseFilter>>& filters, Image& image);
