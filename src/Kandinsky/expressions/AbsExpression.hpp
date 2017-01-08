#ifndef KANDINSKY_ABSEXPRESSION_HPP_
#define KANDINSKY_ABSEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>
#include <Kandinsky/expressions/SignExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    class AbsExpression : public UnaryExpression
    {
    public:
        AbsExpression(BaseExpressionPtr arg)
            : UnaryExpression(arg) {}

        double evaluate() const
        {
            return std::abs(m_arg->evaluate());
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string print() const
        {
            return "abs(" + m_arg->print() + ")";
        }
    };

    template <class ArgT>
    AbsExpression abs(ArgT arg)
    {
        return AbsExpression(BaseExpression::makePtr(arg));
    }
}

#endif

