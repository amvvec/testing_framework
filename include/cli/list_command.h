#pragma once
#ifndef LIST_COMMAND_H
#define LIST_COMMAND_H

#include "cli.h"

#include <iostream>

namespace unit::cli {

class ListCommand : public Command {
public:
    std::string name() const override;
    std::string description() const override;
    int execute(int argc, char** argv) override;
};

} // namespace unit::cli

#endif // !LIST_COMMAND_H
