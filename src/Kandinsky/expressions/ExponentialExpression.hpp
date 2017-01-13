#ifndef KANDINSKY_EXPONENTIALEXPRESSION_HPP_
#define KANDINSKY_EXPONENTIALEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    class ExponentialExpression : public UnaryExpression
    {
    public:
        ExponentialExpression(BaseExpressionPtr arg)
            : UnaryExpression(arg) {}

        double evaluate() const
        {
            return std::exp(m_arg->evaluate());
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string print() const
        {
            return "exp(" + m_arg->print() + ")";
        }
    };

    template <class ArgT>
    ExponentialExpression
    exp(const ArgT& arg)
    {
        return ExponentialExpression(BaseExpression::makePtr(arg));
    }
}

#endif

