#include <Kandinsky/Kandinsky.hpp>

#include <iostream>
#ifndef M_PI
#define M_PI std::acos(-1.0)
#endif
using namespace Kandinsky;

int main (int /*argc*/, char** /*argv*/)
{
    Variable x;
    x.setValue(3);
    assertOrExit(std::abs((erf(x)).differentiate(x).evaluate() - 2.0*std::exp(-1.0*3.0*3.0)/std::sqrt(M_PI) < 1.e-4), "x = 3; d(erf(x))/dx != " + std::to_string(2.0*std::exp(-1.0*3.0*3.0)/std::sqrt(M_PI)));
    return 0;
}