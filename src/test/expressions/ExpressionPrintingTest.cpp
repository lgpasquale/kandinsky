#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main(int /*argc*/, char** /*argv*/)
{
    Variable v("v");
    Constant m(10);
    {
        Expression expression(0.5 * m * v * v);
        v.setValue(2);
        v.setFormatter([](double value) -> std::string { return std::to_string(value) + "m/s"; });
        m.setFormatter([](double value) -> std::string { return std::to_string(value) + "kg"; });
        std::cout << expression.toString() << std::endl;
        assertOrExit(expression.toString() == "((5.000000 * v) * v)", "Wrong parametric string");
        std::cout << expression.toString(true) << std::endl;
        assertOrExit(expression.toString(true) == "((5.000000 * 2.000000m/s) * 2.000000m/s)", "Wrong evaluated string");
    }
    {
        Expression expression(0.5 * (m * v * v));
        v.setValue(2);
        v.setFormatter([](double value) -> std::string { return std::to_string(value) + "m/s"; });
        m.setFormatter([](double value) -> std::string { return std::to_string(value) + "kg"; });
        std::cout << expression.toString() << std::endl;
        assertOrExit(expression.toString() == "(0.500000 * ((10.000000kg * v) * v))", "Wrong parametric string");
        std::cout << expression.toString(true) << std::endl;
        assertOrExit(expression.toString(true) == "(0.500000 * ((10.000000kg * 2.000000m/s) * 2.000000m/s))", "Wrong evaluated string");
    }
    return 0;
}

