#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Expression expression(Constant(2));
    Variable x;
    assertOrExit(expression.differentiate(x).evaluate() == 0, "d(2)/dx != 0");
    return 0;
}

