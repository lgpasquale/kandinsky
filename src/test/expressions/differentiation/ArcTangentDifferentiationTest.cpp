#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    x.setValue(0.5);
    assertOrExit(std::abs((atan(x)).differentiate(x).evaluate() - 1. /  (0.5 * 0.5 + 1.)) < 1.e-4, "x = 0.5; d(atan(x))/dx != " + std::to_string(1. / (0.5 * 0.5 - 1.)));
    return 0;
}

