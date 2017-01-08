#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    x.setValue(3);
    assertOrExit((sign(x)).differentiate(x).evaluate() == 0, "x = 3; d(sign(x))/dx != 0");
    x.setValue(-2);
    assertOrExit((sign(x)).differentiate(x).evaluate() == 0, "x = 3; d(sign(x))/dx != 0");
    return 0;
}

