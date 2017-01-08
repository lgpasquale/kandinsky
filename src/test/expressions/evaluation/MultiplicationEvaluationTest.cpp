#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    Variable y;
    x.setValue(3);
    y.setValue(2);
    assertOrExit((x * y).evaluate() == 6, std::to_string(x.evaluate()) + " * " + std::to_string(y.evaluate()) + " != 6");
    assertOrExit((x * 2).evaluate() == 6, std::to_string(x.evaluate()) + " * 2 != 6");
    assertOrExit((3 * y).evaluate() == 6, "3 * " + std::to_string(y.evaluate()) + " != 6");
    assertOrExit((x * (y * 5)).evaluate() == 30, std::to_string(x.evaluate()) + " * " + std::to_string(y.evaluate()) + " * 5 != 30");
    return 0;
}


