#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    Variable y;
    x.setValue(3);
    y.setValue(2);
    assertOrExit((x <= y).evaluate() == 0, "(" + std::to_string(x.evaluate()) + " <= " + std::to_string(y.evaluate()) + ") != 0");
    assertOrExit((y <= x).evaluate() == 1, "(" + std::to_string(y.evaluate()) + " <= " + std::to_string(x.evaluate()) + ") != 1");
    y.setValue(3);
    assertOrExit((x <= y).evaluate() == 1, "(" + std::to_string(x.evaluate()) + " <= " + std::to_string(y.evaluate()) + ") != 1");
    assertOrExit((x <= 4).evaluate() == 1, "(" + std::to_string(x.evaluate()) + " <= 4) != 1");
    assertOrExit((4 <= x).evaluate() == 0, "(4 <= " + std::to_string(x.evaluate()) + ") != 0");
    return 0;
}

