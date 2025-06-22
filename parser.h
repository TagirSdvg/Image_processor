#pragma once

#include <string>
#include <vector>
#include <stdexcept>

struct InputFilter {
    std::string filter_name;
    std::vector<std::string> filter_params;
};

struct ParserResults {
    std::string input_file;
    std::string output_file;
    std::vector<InputFilter> input_filters;
};

ParserResults Parse(int arg1, char** arg2);
