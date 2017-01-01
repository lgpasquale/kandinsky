#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    x.setValue(3);
    assertOrExit(log(x).evaluate() == std::log(3), "log(" + std::to_string(x.evaluate()) + ") != " + std::to_string(std::log(3)));
    return 0;
}

