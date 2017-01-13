#ifndef KANDINSKY_TANGENTEXPRESSION_HPP_
#define KANDINSKY_TANGENTEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    class TangentExpression : public UnaryExpression
    {
    public:
        TangentExpression(BaseExpressionPtr arg)
            : UnaryExpression(arg) {}

        double evaluate() const
        {
            return std::tan(m_arg->evaluate());
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string print() const
        {
            return "tan(" + m_arg->print() + ")";
        }
    };

    template <class ArgT>
    TangentExpression
    tan(const ArgT& arg)
    {
        return TangentExpression(BaseExpression::makePtr(arg));
    }
}

#endif

