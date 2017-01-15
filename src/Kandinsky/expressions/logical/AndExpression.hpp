#ifndef KANDINSKY_ANDEXPRESSION_HPP_
#define KANDINSKY_ANDEXPRESSION_HPP_

#include <Kandinsky/expressions/BinaryExpression.hpp>
#include <Kandinsky/expressions/VariableExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    class AndExpression : public BinaryExpression
    {
    public:
        AndExpression(BaseExpressionPtr arg1, BaseExpressionPtr arg2)
            : BinaryExpression(arg1, arg2) {}

        double evaluate() const
        {
            return m_arg1->evaluate() && m_arg2->evaluate();
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string print() const
        {
            return m_arg1->print() + " && " + m_arg2->print();
        }
    };

    template <class Arg1T,class Arg2T>
    AndExpression
    operator&&(const Arg1T& arg1, const Arg2T& arg2)
    {
        return AndExpression(BaseExpression::makePtr(arg1), BaseExpression::makePtr(arg2));
    }
}

#endif

