#ifndef KANDINSKY_ARCSINEEXPRESSION_HPP_
#define KANDINSKY_ARCSINEEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    class ArcSineExpression : public UnaryExpression
    {
    public:
        ArcSineExpression(BaseExpressionPtr arg)
            : UnaryExpression(arg) {}

        double evaluate() const
        {
            return std::asin(m_arg->evaluate());
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string print() const
        {
            return "asin(" + m_arg->print() + ")";
        }
    };

    template <class ArgT>
    ArcSineExpression
    asin(ArgT arg)
    {
        return ArcSineExpression(BaseExpression::makePtr(arg));
    }
}

#endif

