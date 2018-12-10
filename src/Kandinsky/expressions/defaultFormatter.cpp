#include <Kandinsky/expressions/defaultFormatter.hpp>

#include <sstream>

namespace Kandinsky
{
    std::string defaultFormatter(double value)
    {
        std::ostringstream out;
        out << value;
        return out.str();
    }
}

