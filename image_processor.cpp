#include "controller.h"
#include "parser.h"
#include "bmp_read.h"
#include "image.h"

int main(int argc, char** argv) {
    ParserResults pars = Parse(argc, argv);
    Image image = BMPRead(pars.input_file);
    ApplyFilters(CreateFilters(pars.input_filters), image);
    BMPWrite(image, pars.output_file);
}
