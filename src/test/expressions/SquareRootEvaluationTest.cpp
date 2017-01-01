#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    x.setValue(4);
    assertOrExit(sqrt(x).evaluate() == 2, "sqrt(" + std::to_string(x.evaluate()) + ") != 2");
    assertOrExit(sqrt(4).evaluate() == 2, "sqrt(4) != 2");
    return 0;
}

