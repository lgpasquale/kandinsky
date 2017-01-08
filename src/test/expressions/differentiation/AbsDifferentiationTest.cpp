#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    x.setValue(3);
    assertOrExit((abs(x)).differentiate(x).evaluate() == 1, "x = 3; d(abs(x))/dx != 1");
    x.setValue(-2);
    assertOrExit((abs(x)).differentiate(x).evaluate() == -1, "x = -2; d(sign(x))/dx != -1");
    return 0;
}

