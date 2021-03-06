#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    x.setValue(3);
    assertOrExit(erf(x).evaluate() == std::erf(3), "erf(" + std::to_string(x.evaluate()) + ") != " + std::to_string(std::erf(3)));
    return 0;
}

