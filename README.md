# Kandinsky - The expressionist

This library allows to handle and differentiate expressions.

To use this library one needs to include "Kandinsky/Kandinsky.hpp".

All types are defined within the namespace `Kandinsky`.

The two main types meant to be used are `Variable` and `Expression`.

Variables hava a name (used to print expressions), a value (used to evaluate expressions) and an index (used to represent their index when assembling a system of equations).
All of these are accessible via getters/setters.

Expressions can be evaluated by calling the `double evaluate()` method and differentiated (w.r.t. a certain variable) by calling `Expression differentiate(const Variable&)`.

A map of all derivatives for an expression can be obtained with the method `std::map<Variable, Expression> derivatives()`.

## Example

```cpp
#include <Kandinsky/Kandinsky.hpp>

#include <iostream>

int main(int, char**)
{
    using Kandinsky::Variable;
    using Kandinsky::Expression;

    Variable x("x"); // the argument is optional and provides a name for printing purposes
    Variable y("y");
    Variable z("z");
    Expression f = x * x + Kandinsky::sqrt(y) * x;

    std::cout << "f(x,y) = " << f.toString() << std::endl;

    x.setValue(3);
    y.setValue(4);
    std::cout << "f(3,4) = " << f.evaluate() << std::endl;
    Expression dfx = f.differentiate(x);
    std::cout << "df/dx (3, 4) = " << dfx.evaluate() << std::endl;

    x.setIndex(0);
    y.setIndex(1);
    z.setIndex(2);
    // Derivatives w.r.t. all variables that appear in the expression
    for (const std::pair<Variable, Expression>& derivative : f.derivatives())
    {
        std::cout << "df/d" << derivative.first.getName() << " = "
                << derivative.second.toString() << std::endl;
        std::cout << "df/d" << derivative.first.getName() << " (3,4) = "
                << derivative.second.evaluate() << std::endl;
    }

    return 0;
}
```
The output produced by the previous code is:
```
f(x,y) = ((x * x) + (sqrt(y) * x))
f(3,4) = 15
df/dx (3, 4) = 8
df/dx = (((1 * x) + (x * 1)) + ((((0.5 / sqrt(y)) * 0) * x) + (sqrt(y) * 1)))
df/dx (3,4) = 8
df/dy = (((0 * x) + (x * 0)) + ((((0.5 / sqrt(y)) * 1) * x) + (sqrt(y) * 0)))
df/dy (3,4) = 0.75
```

## Supported operators

- Basic mathematical operations (`+`, `-`, `*`, `/`) are implemented by operator overloading
- The following functions can be found within the namespace `Kandinsky`:  
  `cos`, `sin`, `tan`, `acos`, `asin`, `atan`, `pow`, `sqrt`, `exp`, `log`,
  `abs`, `sign`
- Comparison operators (`==`, `!=`, `>`, `>=`, `<`, `<=`) are also overloaded
  for `Expressions` (they return an `Expression`, not a `bool`; once this `Expression` is evaluated it returns either 0 or 1)
- The ternary conditional operator `? :` is provided by the function
  `ifThenElse` (because c++ doesn't allow overloading of the ternary operator
  `? :`)

The following example showcases conditional expressions:
```cpp
Variable x("x");
Expression f = ifThenElse(x > 0, x * x, 3);
x.setValue(2);
std::cout << "f(2) = " << f.evaluate() << std::endl; // f(2) = 4
x.setValue(-2);
std::cout << "f(-2) = " << f.evaluate() << std::endl; // f(-2) = 3
```

## Installation

Kandinsky can be installed like any other CMake library:
```sh
mkdir /some/build/dir
cd /some/build/dir
cmake -D CMAKE_INSTALL_PREFIX=/some/install/dir /kandinsy/source/dir
make
make install
```
Be sure to substitute `/some/build/dir` and `/some/install/dir` with suitable
directories, and to replace `/kandinsy/source/dir` with the directory containing this README.
