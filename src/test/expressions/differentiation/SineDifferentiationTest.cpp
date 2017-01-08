#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    x.setValue(3);
    assertOrExit(std::abs((sin(x)).differentiate(x).evaluate() - std::cos(3)) < 1.e-4, "x = 3; d(sin(x))/dx != " + std::to_string(std::cos(3)));
    return 0;
}

