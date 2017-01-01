#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    Variable y;
    x.setValue(3);
    y.setValue(2);
    assertOrExit((x + y).evaluate() == 5, std::to_string(x.evaluate()) + " + " + std::to_string(y.evaluate()) + " != 5");
    assertOrExit((x + 1).evaluate() == 4, std::to_string(x.evaluate()) + " + 1 != 4");
    assertOrExit((1 + x).evaluate() == 4, "1 + " + std::to_string(x.evaluate()) + " != 4");
    assertOrExit((x + 1 + y).evaluate() == 6, std::to_string(x.evaluate()) + " + 1 + " + std::to_string(y.evaluate()) + " != 6");
    assertOrExit((+x).evaluate() == 3, "+ " + std::to_string(x.evaluate()) + " != 6");
    assertOrExit((+x + 2).evaluate() == 5, "+ " + std::to_string(x.evaluate()) + " + 2 != 5");

    return 0;
}


