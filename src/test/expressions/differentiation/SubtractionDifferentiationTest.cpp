#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    Variable y;
    x.setValue(3);
    y.setValue(2);
    assertOrExit((x - y).differentiate(x).evaluate() == 1, "d(x - y)/dx != 1");
    assertOrExit((x - y).differentiate(y).evaluate() == -1, "d(x - y)/dy != -1");
    assertOrExit((4 - (x - y)).differentiate(x).evaluate() == -1, "d(4 - (x - y))/dx != -1");
    assertOrExit((4 - (x - y)).differentiate(y).evaluate() == 1, "d(4 - (x - y))/dy != 1");
    Expression expression(4 - (x - y));
    assertOrExit(expression.differentiate(y).evaluate() == 1, "d(4 - (x - y))/dy != 1");
    return 0;
}

