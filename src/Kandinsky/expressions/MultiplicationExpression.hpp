#ifndef KANDINSKY_MULTIPLICATIONEXPRESSION_HPP_
#define KANDINSKY_MULTIPLICATIONEXPRESSION_HPP_

#include <Kandinsky/expressions/BinaryExpression.hpp>
#include <Kandinsky/expressions/AdditionExpression.hpp>

namespace Kandinsky
{
    class MultiplicationExpression : public BinaryExpression
    {
    public:
        MultiplicationExpression(BaseExpressionPtr arg1, BaseExpressionPtr arg2)
            : BinaryExpression(arg1, arg2) {}

        double evaluate() const
        {
            return m_arg1->evaluate() * m_arg2->evaluate();
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string print() const
        {
            return m_arg1->print() + " * " + m_arg2->print();
        }
    };

    template <class Arg1T,class Arg2T>
    MultiplicationExpression
    operator*(Arg1T arg1, Arg2T arg2)
    {
        return MultiplicationExpression(BaseExpression::makePtr(arg1), BaseExpression::makePtr(arg2));
    }

    template <class Arg1T, class Arg2T>
    Arg1T&
    operator*=(Arg1T& arg1, const Arg2T& arg2)
    {
        arg1 = arg1 * arg2;
        return arg1;
    }
}

#endif

