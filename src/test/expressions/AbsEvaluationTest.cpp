#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    x.setValue(1);
    assertOrExit(abs(x).evaluate() == 1, "abs(" + std::to_string(x.evaluate()) + ") != 1");
    x.setValue(-1);
    assertOrExit(abs(x).evaluate() == 1, "abs(" + std::to_string(x.evaluate()) + ") != -1");
    return 0;
}


