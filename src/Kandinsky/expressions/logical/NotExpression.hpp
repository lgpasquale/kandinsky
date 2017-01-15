#ifndef KANDINSKY_NOTEXPRESSION_HPP_
#define KANDINSKY_NOTEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>
#include <Kandinsky/expressions/VariableExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    class NotExpression : public UnaryExpression
    {
    public:
        NotExpression(BaseExpressionPtr arg)
            : UnaryExpression(arg) {}

        double evaluate() const
        {
            return !(m_arg->evaluate());
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string print() const
        {
            return "!" + m_arg->print() + "";
        }
    };

    template <class ArgT>
    NotExpression
    operator!(const ArgT& arg)
    {
        return NotExpression(BaseExpression::makePtr(arg));
    }
}

#endif

