#include "cli/cli.h"

#include <iostream>

int main(int argc, char** argv) {
    return unit::cli::parse_argument(argc, argv);
}
