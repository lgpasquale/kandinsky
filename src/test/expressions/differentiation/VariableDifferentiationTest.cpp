#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    Variable y;
    x.setValue(3);
    assertOrExit(x.differentiate(x).evaluate() == 1, "d(x)/dx != 1");
    assertOrExit(x.differentiate(y).evaluate() == 0, "d(y)/dx != 0");
    Expression expression(x);
    assertOrExit(expression.differentiate(x).evaluate() == 1, "d(x)/dx != 1");
    assertOrExit(expression.differentiate(y).evaluate() == 0, "d(y)/dx != 0");
    return 0;
}

