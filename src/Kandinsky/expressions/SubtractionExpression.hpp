#ifndef KANDINSKY_SUBTRACTIONEXPRESSION_HPP_
#define KANDINSKY_SUBTRACTIONEXPRESSION_HPP_

#include <Kandinsky/expressions/BinaryExpression.hpp>

namespace Kandinsky
{
    class SubtractionExpression : public BinaryExpression
    {
    public:
        SubtractionExpression(BaseExpressionPtr arg1, BaseExpressionPtr arg2)
            : BinaryExpression(arg1, arg2) {}

        double evaluate() const
        {
            return m_arg1->evaluate() - m_arg2->evaluate();
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string print() const
        {
            return m_arg1->print() + " - " + m_arg2->print();
        }
    };

    template <class Arg1T,class Arg2T>
    SubtractionExpression
    operator-(Arg1T arg1, Arg2T arg2)
    {
        return SubtractionExpression(BaseExpression::makePtr(arg1), BaseExpression::makePtr(arg2));
    }

    template <class Arg1T, class Arg2T>
    Arg1T&
    operator-=(Arg1T& arg1, const Arg2T& arg2)
    {
        arg1 = arg1 - arg2;
        return arg1;
    }
}

#endif

