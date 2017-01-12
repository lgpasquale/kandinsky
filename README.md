# Kandinsky - The expressionist

This library allows to handle and differentiate expressions.

To use this library one needs to include "Kandinsky/Kandinsky.hpp".

All types are defined within the namespace `Kandinsky`.

The two main types meant to be used are `Variable` and `Expression`.

Variables hava a name (used to print expressions), a value (used to evaluate expressions) and an index (used to represent their index when assembling a system of equations).
All of these are accessible via getters/setters.

Expressions can be evaluated by calling the `double evaluate()` method and differentiated by calling `Expression differentiate(const Variable&)`.

A map of all derivatives for an expression can be obtained with the method `std::map<Variable, Expression> derivatives()`.

## Example
```cpp
#include <Kandinksy/Kandinsky.hpp>

#include <iostream>

int main(int, char**)
{
    using Kandinsky::Variable;
    using Kandinsky::Expression;

    Variable x("x"); // the argument is optional and provides a name for printing purposes
    Variable y("y");
    Variable z("z");
    Expression f = x * x + Kandinsky::sqrt(y) * x;

    std::cout << "f(x,y) = " << f.print() << std::endl;

    x.setValue(3);
    y.setValue(4);
    std::cout << "f(3,4) = " << f.evaluate() << std::endl;

    for (const std::pair<Variable, Expression>& derivative : f.derivatives())
    {
        std::cout << "df/d" << derivative.first.getName() << " = "
                << derivative.second.print() << std::endl
        std::cout << "df/d" << derivative.first.getName() << " (3,4) = "
                << derivative.second.evaluate() << std::endl
    }

    return 0;
}
```
The output produced by the previous code is:
```
f(x,y) = x * x + sqrt(y) * x
f(3,4) = 15
df/dx = 1.000000 * x + x * 1.000000 + 0.500000 / sqrt(y) * 0.000000 * x + sqrt(y) * 1.000000
df/dx (3,4) = 8
```

