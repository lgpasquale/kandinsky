#ifndef KANDINSKY_NATURALLOGARITHMEXPRESSION_HPP_
#define KANDINSKY_NATURALLOGARITHMEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    class NaturalLogarithmExpression : public UnaryExpression
    {
    public:
        NaturalLogarithmExpression(BaseExpressionPtr arg)
            : UnaryExpression(arg) {}

        double evaluate() const
        {
            return std::log(m_arg->evaluate());
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string print() const
        {
            return "log(" + m_arg->print() + ")";
        }
    };

    template <class ArgT>
    NaturalLogarithmExpression
    log(const ArgT& arg)
    {
        return NaturalLogarithmExpression(BaseExpression::makePtr(arg));
    }
}

#endif

