#ifndef KANDINSKY_CONSTANT_HPP_
#define KANDINSKY_CONSTANT_HPP_

#include <Kandinsky/expressions/BaseExpression.hpp>
#include <Kandinsky/expressions/VariableExpression.hpp>

namespace Kandinsky
{
    class Constant : public BaseExpression
    {
    public:
        Constant(double value) : m_value(value) {}

        double evaluate() const
        {
            return m_value;
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual void fillVariableSet(std::set<Variable>& /*variableSet*/, const BaseExpressionPtr& /*thisSharedPtr*/) const
        {
        }

        virtual std::string print() const
        {
            return std::to_string(m_value);
        }

    private:
        double m_value;
    };

    typedef std::shared_ptr<Constant> ConstantPtr;
}

#endif

