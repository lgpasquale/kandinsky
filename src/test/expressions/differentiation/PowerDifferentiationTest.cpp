#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    x.setValue(3);
    assertOrExit(std::abs((pow(x, 5)).differentiate(x).evaluate() - 405) < 1.e-4, "x = 3; d(pow(x,5))/dx != 405");
    assertOrExit(std::abs((pow(4, x)).differentiate(x).evaluate() - 64*std::log(4)) < 1.e-4, "x = 3; d(pow(4,x))/dx != " + std::to_string(64*std::log(4)));
    x.setValue(0);
    assertOrExit(std::abs((pow(x, 5)).differentiate(x).evaluate() - 0) < 1.e-4, "x = 0; d(pow(x,5))/dx != 0");
    return 0;
}

