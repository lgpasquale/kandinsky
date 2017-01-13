#ifndef KANDINSKY_MINUSEXPRESSION_HPP_
#define KANDINSKY_MINUSEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>

namespace Kandinsky
{
    class MinusExpression : public UnaryExpression
    {
    public:
        MinusExpression(BaseExpressionPtr arg)
            : UnaryExpression(arg) {}

        double evaluate() const
        {
            return -m_arg->evaluate();
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string print() const
        {
            return "- " + m_arg->print();
        }
    };

    template <class ArgT>
    MinusExpression operator-(const ArgT& arg)
    {
        return MinusExpression(BaseExpression::makePtr(arg));
    }
}

#endif

