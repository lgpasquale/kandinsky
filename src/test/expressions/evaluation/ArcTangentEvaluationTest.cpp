#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    x.setValue(0.5);
    assertOrExit(atan(x).evaluate() == std::atan(0.5),
            "atan(" + std::to_string(x.evaluate()) + ") != " + std::to_string(std::atan(0.5)));
    return 0;
}

