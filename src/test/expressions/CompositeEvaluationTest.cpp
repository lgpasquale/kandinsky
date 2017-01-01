#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    Variable y;
    x.setValue(3);
    y.setValue(2);
    assertOrExit((x * (x + y)).evaluate() == 15, std::to_string(x.evaluate()) + " * (" + std::to_string(x.evaluate()) + " + " + std::to_string(y.evaluate()) + ") != 15");
    assertOrExit((x * x + y).evaluate() == 11, std::to_string(x.evaluate()) + " * " + std::to_string(x.evaluate()) + " + " + std::to_string(y.evaluate()) + " != 11");

    return 0;
}


