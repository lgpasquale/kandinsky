#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    Variable y;
    x.setValue(3);
    y.setValue(2);
    assertOrExit((ifThenElse(x > y, x, y)).evaluate() == 3,
            "(" + std::to_string(x.evaluate()) + " > " + std::to_string(y.evaluate()) + ") ? "
            + std::to_string(x.evaluate()) + " : " + std::to_string(y.evaluate()) + " != 3");
    assertOrExit((ifThenElse(x > 4, x, 4)).evaluate() == 4,
            "(" + std::to_string(x.evaluate()) + " > 4) ? "
            + std::to_string(x.evaluate()) + " : 4 != 4");
    return 0;
}

