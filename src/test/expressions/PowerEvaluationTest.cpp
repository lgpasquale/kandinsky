#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    Variable y;
    x.setValue(3);
    y.setValue(2);
    assertOrExit(pow(x, y).evaluate() == 9, std::to_string(x.evaluate()) + " ^ " + std::to_string(y.evaluate()) + " != 9");
    assertOrExit(pow(x, 2).evaluate() == 9, std::to_string(x.evaluate()) + " ^ 2 != 9");
    return 0;
}

