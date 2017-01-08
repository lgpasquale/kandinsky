#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    x.setValue(3);
    assertOrExit(std::abs((exp(x)).differentiate(x).evaluate() - std::exp(3)) < 1.e-4, "x = 3; d(exp(x))/dx != " + std::to_string(std::exp(3)));
    return 0;
}

