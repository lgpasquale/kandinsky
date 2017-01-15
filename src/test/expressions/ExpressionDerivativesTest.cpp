#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main(int /*argc*/, char** /*argv*/)
{
    Variable x;
    Variable y;
    Variable z;
    x.setIndex(0);
    y.setIndex(1);
    z.setIndex(2);
    {
        Expression expression(x+x+x*y);
        assertOrExit(expression.derivatives().size() == 2, "x + x + x * y should contain only two variables");
        x.setValue(2);
        y.setValue(3);
        z.setValue(5);
        assertOrExit(std::abs(expression.derivatives().at(x).evaluate() - 5) < 1.e-4, "y = 3; 1 + 1 + y != 5");
        Variable x1 = x;
        assertOrExit(std::abs(expression.derivatives().at(x).evaluate() - 5) < 1.e-4, "y = 3; 1 + 1 + y != 5");
    }
    {
        Expression expression((x < 2) * x * x + (x >= 2 && y < 0) * sin(x) + (x>= 2 && y >= 0) * (-x));
        x.setValue(1);
        y.setValue(2);
        assertOrExit(std::abs(expression.derivatives().at(x).evaluate() - 2) < 1.e-4, "x = 1; 2 * x != 2");
        x.setValue(3);
        assertOrExit(std::abs(expression.derivatives().at(x).evaluate() - (-1)) < 1.e-4, "-1 != -1");
        x.setValue(3);
        y.setValue(-1);
        assertOrExit(std::abs(expression.derivatives().at(x).evaluate() - std::cos(3)) < 1.e-4, "x = 3; cos(x) != cos(3)");

    }
    return 0;
}

