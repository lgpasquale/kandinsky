#ifndef KANDINSKY_ASSERTOREXIT_HPP_
#define KANDINSKY_ASSERTOREXIT_HPP_

#include <iostream>
#include <string>

namespace Kandinsky
{
    inline void assertOrExit(bool condition, std::string errorMessage)
    {
        if (!condition)
        {
            std::cerr << errorMessage << std::endl;
            exit(1);
        }
    }
}

#endif
