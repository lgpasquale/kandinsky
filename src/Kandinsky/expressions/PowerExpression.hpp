#ifndef KANDINSKY_POWEREXPRESSION_HPP_
#define KANDINSKY_POWEREXPRESSION_HPP_

#include <Kandinsky/expressions/BinaryExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    class PowerExpression : public BinaryExpression
    {
    public:
        PowerExpression(BaseExpressionPtr arg1, BaseExpressionPtr arg2)
            : BinaryExpression(arg1, arg2) {}

        double evaluate() const
        {
            return std::pow(m_arg1->evaluate(), m_arg2->evaluate());
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string print() const
        {
            return "pow(" + m_arg1->print() + ", " + m_arg2->print() + ")";
        }
    };

    template <class Arg1T,class Arg2T>
    PowerExpression
    pow(const Arg1T& arg1, const Arg2T& arg2)
    {
        return PowerExpression(BaseExpression::makePtr(arg1), BaseExpression::makePtr(arg2));
    }
}

#endif

