#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    x.setValue(3);
    assertOrExit(x.evaluate() == 3, std::to_string(x.evaluate()) + " != 3");
    x.setValue(1);
    assertOrExit(x.evaluate() == 1, std::to_string(x.evaluate()) + " != 1");
    return 0;
}

