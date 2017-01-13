#ifndef KANDINSKY_ARCCOSINEEXPRESSION_HPP_
#define KANDINSKY_ARCCOSINEEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    class ArcCosineExpression : public UnaryExpression
    {
    public:
        ArcCosineExpression(BaseExpressionPtr arg)
            : UnaryExpression(arg) {}

        double evaluate() const
        {
            return std::acos(m_arg->evaluate());
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string print() const
        {
            return "acos(" + m_arg->print() + ")";
        }
    };

    template <class ArgT>
    ArcCosineExpression
    acos(const ArgT& arg)
    {
        return ArcCosineExpression(BaseExpression::makePtr(arg));
    }
}

#endif

