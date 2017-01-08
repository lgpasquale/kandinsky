#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    x.setValue(3);
    assertOrExit((- x).differentiate(x).evaluate() == -1, "d(-x)/dx != -1");
    assertOrExit((-(- x)).differentiate(x).evaluate() == 1, "d(-(-x))/dx != 1");
    return 0;
}

