#pragma once
#ifndef CLI_H
#define CLI_H

#include <memory>
#include <string>
#include <vector>

namespace unit::cli {

class Command {
public:
    virtual ~Command() = default;
    virtual std::string name() const = 0;
    virtual std::string description() const = 0;
    virtual int execute(int argc, char** argv) = 0;
};

std::vector<std::unique_ptr<Command>> get_all_commands();
Command* find_command(const std::string& name);

} // namespace unit::cli

#endif // !CLI_H
