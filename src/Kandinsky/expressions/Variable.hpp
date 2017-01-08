#ifndef KANDINSKY_VARIABLE_HPP_
#define KANDINSKY_VARIABLE_HPP_

#include <Kandinsky/expressions/VariableExpression.hpp>
#include <Kandinsky/expressions/Expression.hpp>

namespace Kandinsky
{
    class Variable
    {
    public:
        Variable(double value) : m_variableExpressionPtr(new VariableExpression(value)) {}

        Variable() : Variable(0) {}

        Variable(const std::string& name, double value = 0) :
                m_variableExpressionPtr(new VariableExpression(name, value)) {}

        void setValue(double value)
        {
            m_variableExpressionPtr->setValue(value);
        }

        double getValue() const
        {
            return m_variableExpressionPtr->getValue();
        }

        void setName(const std::string& name)
        {
            m_variableExpressionPtr->setName(name);
        }

        const std::string& getName() const
        {
            return m_variableExpressionPtr->getName();
        }

        double evaluate() const
        {
            return m_variableExpressionPtr->evaluate();
        }

        std::shared_ptr<BaseExpression> derivative(const std::shared_ptr<VariableExpression>& variable) const
        {
            return m_variableExpressionPtr->derivative(variable);
        }

        virtual Expression differentiate(const Variable& variable) const
        {
            return m_variableExpressionPtr->differentiate(variable);
        }

        VariableExpressionPtr getVariableExpressionPtr() const
        {
            return m_variableExpressionPtr;
        }

        bool operator==(const Variable& variable) const
        {
            return m_variableExpressionPtr == variable.getVariableExpressionPtr();
        }

    protected:
        VariableExpressionPtr m_variableExpressionPtr;
    };
}

#endif

