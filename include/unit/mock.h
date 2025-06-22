#include <unit/unit.h>

namespace unit
{
namespace mock
{
struct MockCall
{
    std::string function_name;
    std::vector<std::string> args;
};

struct MockFunction
{
private:
    int call_count = 0;

public:
    std::function<void()> body;

    int call() const
    {
        return call_count;
    }

    bool is_called() const
    {
        return call_count > 0;
    }

    void operator()()
    {
        ++call_count;
        if(body) body();
    }
};
} // namespace mock
} // namespace unit
