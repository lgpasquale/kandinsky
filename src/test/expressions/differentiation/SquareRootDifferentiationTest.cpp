
#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    x.setValue(3);
    assertOrExit(std::abs((sqrt(x)).differentiate(x).evaluate() - 0.5 / std::sqrt(3)) < 1.e-4, "x = 3; d(sqrt(x))/dx != 0.5 / sqrt(3)");
    assertOrExit(std::abs((pow(4, x)).differentiate(x).evaluate() - 64*std::log(4)) < 1.e-4, "x = 3; d(pow(4,x))/dx != " + std::to_string(64*std::log(4)));
    return 0;
}
