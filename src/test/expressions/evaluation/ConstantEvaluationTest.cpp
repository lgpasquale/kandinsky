#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Constant c(2);
    assertOrExit(c.evaluate() == 2, std::to_string(c.evaluate()) + " != 2");
    return 0;
}
