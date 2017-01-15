#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    Variable y;
    x.setValue(3);
    y.setValue(0);
    assertOrExit((!x).evaluate() == 0, "!" + std::to_string(x.evaluate()) + " != 0");
    assertOrExit((!y).evaluate() == 1, "!" + std::to_string(x.evaluate()) + " != 1");
    return 0;
}

