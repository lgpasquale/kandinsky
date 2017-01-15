#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    Variable y;
    x.setValue(3);
    y.setValue(2);
    assertOrExit((x >= y).evaluate() == 1, "(" + std::to_string(x.evaluate()) + " >= " + std::to_string(y.evaluate()) + ") != 1");
    assertOrExit((y >= x).evaluate() == 0, "(" + std::to_string(y.evaluate()) + " >= " + std::to_string(x.evaluate()) + ") != 0");
    y.setValue(3);
    assertOrExit((x >= y).evaluate() == 1, "(" + std::to_string(x.evaluate()) + " >= " + std::to_string(y.evaluate()) + ") != 1");
    assertOrExit((x >= 4).evaluate() == 0, "(" + std::to_string(x.evaluate()) + " >= 4) != 0");
    assertOrExit((4 >= x).evaluate() == 1, "(4 >= " + std::to_string(x.evaluate()) + ") != 1");
    return 0;
}

