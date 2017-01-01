#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    Variable y;
    x.setValue(3);
    y.setValue(2);
    assertOrExit((x / y).evaluate() == 1.5, std::to_string(x.evaluate()) + " / " + std::to_string(y.evaluate()) + " != 1.5");
    assertOrExit((1 / y).evaluate() == 0.5, "1 / " + std::to_string(y.evaluate()) + " != 0.5");
    assertOrExit((x / 2).evaluate() == 1.5, std::to_string(x.evaluate()) + " / 2 != 1.5");
    return 0;
}


