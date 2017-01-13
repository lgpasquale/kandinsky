#ifndef KANDINSKY_SQUAREROOTEXPRESSION_HPP_
#define KANDINSKY_SQUAREROOTEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    class SquareRootExpression : public UnaryExpression
    {
    public:
        SquareRootExpression(BaseExpressionPtr arg)
            : UnaryExpression(arg) {}

        double evaluate() const
        {
            return std::sqrt(m_arg->evaluate());
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string print() const
        {
            return "sqrt(" + m_arg->print() + ")";
        }
    };

    template <class ArgT>
    SquareRootExpression
    sqrt(const ArgT& arg)
    {
        return SquareRootExpression(BaseExpression::makePtr(arg));
    }
}

#endif

