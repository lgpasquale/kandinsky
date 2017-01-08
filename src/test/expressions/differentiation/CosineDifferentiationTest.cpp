#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    x.setValue(3);
    assertOrExit(std::abs((cos(x)).differentiate(x).evaluate() + std::sin(3)) < 1.e-4, "x = 3; d(cos(x))/dx != " + std::to_string(-std::sin(3)));
    return 0;
}

