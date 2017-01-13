#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    Variable y;
    x.setValue(3);
    y.setValue(2);
    assertOrExit((x - y).evaluate() == 1, std::to_string(x.evaluate()) + " - " + std::to_string(y.evaluate()) + " != 1");
    assertOrExit((x - 2).evaluate() == 1, std::to_string(x.evaluate()) + " - 2 != 1");
    assertOrExit((3 - y).evaluate() == 1, "3 - " + std::to_string(y.evaluate()) + " != 1");
    assertOrExit((x - y - 1).evaluate() == 0, std::to_string(x.evaluate()) + " - " + std::to_string(y.evaluate()) + " - 1 != 0");
    assertOrExit((-x).evaluate() == -3, "- " + std::to_string(x.evaluate()) + " != -3");
    assertOrExit((-x - 1).evaluate() == -4, "- " + std::to_string(x.evaluate()) + " - 1 != -3");
    Expression expression;
    expression -= x;
    expression -= y;
    expression -= 1;
    assertOrExit(std::abs(expression.evaluate() + 6) < 1.e-4, "- 3 - 2 - 1 != -6");
    return 0;
}


