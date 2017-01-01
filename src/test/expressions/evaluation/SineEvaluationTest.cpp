#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    x.setValue(3);
    assertOrExit(Kandinsky::sin(x).evaluate() == std::sin(3),
            "sin(" + std::to_string(x.evaluate()) + ") != " + std::to_string(std::sin(3)));
    return 0;
}

