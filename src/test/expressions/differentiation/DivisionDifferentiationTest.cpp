#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    Variable y;
    x.setValue(3);
    y.setValue(2);
    assertOrExit(std::abs((x / y).differentiate(x).evaluate() - 0.5) < 1.e-4, "y = 2; d(x / y)/dx != 0.5");
    assertOrExit(std::abs((x / y).differentiate(y).evaluate() - (-3./4)) < 1.e-4, "x = 3; d(x / y)/dy != -3/4");
    assertOrExit(std::abs((x / 5).differentiate(x).evaluate() - 1./5) < 1.e-4, "d(x / 5)/dx != 0.2");
    assertOrExit(std::abs((4 / (y / x)).differentiate(x).evaluate() - 2) < 1.e-4, "d(4 / (y / x))/dx != 2");
    return 0;
}

