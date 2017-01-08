#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    x.setValue(3);
    assertOrExit(std::abs((tan(x)).differentiate(x).evaluate() - 1. / std::cos(3) / std::cos(3)) < 1.e-4, "x = 3; d(tan(x))/dx != " + std::to_string(1 / std::cos(3) / std::cos(3)));
    return 0;
}

