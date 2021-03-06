#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    x.setValue(3);
    assertOrExit(exp(x).evaluate() == std::exp(3), "e ^ " + std::to_string(x.evaluate()) + " != " + std::to_string(std::exp(3)));
    return 0;
}

