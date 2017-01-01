#ifndef KANDINSKY_EXPRESSION_HPP_
#define KANDINSKY_EXPRESSION_HPP_

namespace Kandinsky
{
    class Expression
    {
    public:
        virtual double evaluate() const = 0;
    };
}

#endif
