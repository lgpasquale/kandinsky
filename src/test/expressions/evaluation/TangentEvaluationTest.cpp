#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    x.setValue(3);
    assertOrExit(tan(x).evaluate() == std::tan(3),
            "tan(" + std::to_string(x.evaluate()) + ") != " + std::to_string(std::tan(3)));
    return 0;
}

