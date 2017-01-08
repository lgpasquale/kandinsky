#ifndef KANDINSKY_ARCTANGENTEXPRESSION_HPP_
#define KANDINSKY_ARCTANGENTEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    class ArcTangentExpression : public UnaryExpression
    {
    public:
        ArcTangentExpression(BaseExpressionPtr arg)
            : UnaryExpression(arg) {}

        double evaluate() const
        {
            return std::atan(m_arg->evaluate());
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string print() const
        {
            return "atan(" + m_arg->print() + ")";
        }
    };

    template <class ArgT>
    ArcTangentExpression
    atan(ArgT arg)
    {
        return ArcTangentExpression(BaseExpression::makePtr(arg));
    }
}

#endif

