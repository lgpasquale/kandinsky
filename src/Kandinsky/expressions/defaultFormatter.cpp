#include <Kandinsky/expressions/defaultFormatter.hpp>

namespace Kandinsky
{
    std::string defaultFormatter(double value)
    {
        return std::to_string(value);
    }
}

