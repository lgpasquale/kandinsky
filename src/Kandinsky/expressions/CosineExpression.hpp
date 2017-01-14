#ifndef KANDINSKY_COSINEEXPRESSION_HPP_
#define KANDINSKY_COSINEEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>
#include <Kandinsky/expressions/VariableExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    class CosineExpression : public UnaryExpression
    {
    public:
        CosineExpression(BaseExpressionPtr arg)
            : UnaryExpression(arg) {}

        double evaluate() const
        {
            return std::cos(m_arg->evaluate());
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string print() const
        {
            return "cos(" + m_arg->print() + ")";
        }
    };

    template <class ArgT>
    CosineExpression
    cos(const ArgT& arg)
    {
        return CosineExpression(BaseExpression::makePtr(arg));
    }
}

#endif

