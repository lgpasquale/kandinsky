#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    x.setValue(3);
    assertOrExit(std::abs((log(x)).differentiate(x).evaluate() - 1. / 3) < 1.e-4, "x = 3; d(log(x))/dx != 1 / 3");
    return 0;
}

