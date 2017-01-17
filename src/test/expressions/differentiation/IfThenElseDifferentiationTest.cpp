
#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    Variable y;
    x.setValue(3);
    y.setValue(2);
    assertOrExit((ifThenElse(x > y, x, y)).differentiate(x).evaluate() == 1,
            "x = 3; y = 2; d((" + std::to_string(x.evaluate()) + " > " + std::to_string(y.evaluate()) + ") ? "
            + std::to_string(x.evaluate()) + " : " + std::to_string(y.evaluate()) + ")/dx != 1");
    y.setValue(4);
    assertOrExit((ifThenElse(x > 4, x, 4)).evaluate() == 4,
            "x = 3; y = 4; d((" + std::to_string(x.evaluate()) + " > 4) ? "
            + std::to_string(x.evaluate()) + " : 4)/dx != 0");
    return 0;
}
