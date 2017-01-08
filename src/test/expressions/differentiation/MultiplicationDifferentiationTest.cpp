#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    Variable y;
    x.setValue(3);
    y.setValue(2);
    assertOrExit((x * y).differentiate(x).evaluate() == 2, "d(x * y)/dx != 2");
    assertOrExit((x * y).differentiate(y).evaluate() == 3, "d(x * y)/dy != 3");
    assertOrExit((4 * (x * y)).differentiate(x).evaluate() == 8, "y = 2; d(4 * (x * y))/dx != 8");
    Expression expression(4 * (x * y));
    assertOrExit(expression.differentiate(y).evaluate() == 12, "x = 3; d(4 * (x * y))/dy != 12");
    x.setValue(5);
    assertOrExit(expression.differentiate(y).evaluate() == 20, "x = 5; d(4 * (x * y))/dy != 20");
    return 0;
}

