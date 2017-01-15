#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    Variable y;
    x.setValue(3);
    y.setValue(0);
    assertOrExit((x && y).evaluate() == 0, std::to_string(x.evaluate()) + " && " + std::to_string(y.evaluate()) + " != 0");
    assertOrExit((x && 1).evaluate() == 1, std::to_string(x.evaluate()) + " && 1 != 1");
    assertOrExit((1 && x).evaluate() == 1, "1 && " + std::to_string(x.evaluate()) + " != 1");
    return 0;
}

