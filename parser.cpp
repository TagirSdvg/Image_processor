#include "parser.h"
#include "exceptions.h"

ParserResults Parse(int argс, char** argv) {
    ParserResults results;

    if (argс == 1) {
        throw ParserException("not enough args for parsing");
    } else if (argс == 2) {
        throw ParserException("not enough args for parsing");
    }

    results.input_file = argv[1];
    results.output_file = argv[2];

    for (int i = 3; i < argс; ++i) {
        std::string arg = argv[i];
        if (arg[0] == '-') {
            InputFilter filter;
            filter.filter_name = arg.substr(1);
            while (i + 1 < argс && argv[i + 1][0] != '-') {
                filter.filter_params.push_back(argv[++i]);
            }
            results.input_filters.push_back(filter);
        } else {
            throw ParserException("incorrect input");
        }
    }
    return results;
}
