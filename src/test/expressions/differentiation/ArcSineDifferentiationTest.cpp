#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    x.setValue(0.5);
    assertOrExit(std::abs((asin(x)).differentiate(x).evaluate() - 1. /  std::sqrt(1. - 0.5 * 0.5)) < 1.e-4, "x = 0.5; d(asin(x))/dx != " + std::to_string(1. / std::sqrt(1. - 0.5 * 0.5)));
    return 0;
}

