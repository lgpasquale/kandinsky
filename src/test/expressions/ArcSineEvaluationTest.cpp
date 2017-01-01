#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    x.setValue(0.5);
    std::cout << asin(x).evaluate() << std::endl;
    assertOrExit(std::abs(asin(x).evaluate() - std::asin(0.5)) < 1.e-4,
            "asin(" + std::to_string(x.evaluate()) + ") != " + std::to_string(std::asin(0.5)));
    return 0;
}

