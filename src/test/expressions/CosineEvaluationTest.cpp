#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    x.setValue(3);
    assertOrExit(Kandinsky::cos(x).evaluate() == std::cos(3),
            "cos(" + std::to_string(x.evaluate()) + ") != " + std::to_string(std::cos(3)));
    return 0;
}

