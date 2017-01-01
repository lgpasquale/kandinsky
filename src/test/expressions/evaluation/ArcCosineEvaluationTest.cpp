#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    x.setValue(0.5);
    assertOrExit(acos(x).evaluate() == std::acos(0.5),
            "acos(" + std::to_string(x.evaluate()) + ") != " + std::to_string(std::acos(0.5)));
    return 0;
}

