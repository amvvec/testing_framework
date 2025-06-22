#include <unit/unit.h>
#include <iostream>

int main(int argc, char **argv)
{
    auto option = ::unit::parse_argument(argc, argv);
    
    if(option.list_only)
    {
        std::cout << "[ List test ]" << std::endl << std::endl;
    }
    
    std::string filter;

    for(int i = 0; i < argc; i++)
    {
        std::string arg = argv[i];
        
        const std::string prefix = "--filter=";

        if(arg.find(prefix) == 0)
        {
            filter = arg.substr(prefix.size());
        }
    }

    std::cout << std::endl;
    return ::unit::run_all_tests(option.filter,
                                 option.list_only);
}
