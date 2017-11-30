#ifndef KANDINSKY_VARIABLE_HPP_
#define KANDINSKY_VARIABLE_HPP_

#include <Kandinsky/expressions/VariableExpression.hpp>
#include <Kandinsky/expressions/Expression.hpp>

namespace Kandinsky
{
    class Variable
    {
    public:
        Variable(double value) : m_variableExpressionPtr(std::make_shared<VariableExpression>(value)) {}

        Variable() : Variable(0) {}

        Variable(const std::string& name, double value = 0) :
                m_variableExpressionPtr(std::make_shared<VariableExpression>(name, value)) {}

        Variable(VariableExpressionPtr variableExpressionPtr) :
                m_variableExpressionPtr(variableExpressionPtr) {}

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

        void setIndex(unsigned int index)
        {
            m_variableExpressionPtr->setIndex(index);
        }

        unsigned int getIndex() const
        {
            return m_variableExpressionPtr->getIndex();
        }

        double evaluate() const
        {
            return m_variableExpressionPtr->evaluate();
        }

        std::shared_ptr<BaseExpression> derivative(const std::shared_ptr<VariableExpression>& variable) const;

        virtual Expression differentiate(const Variable& variable) const;

        VariableExpressionPtr getVariableExpressionPtr() const
        {
            return m_variableExpressionPtr;
        }

        bool sameAs(const Variable& variable) const
        {
            return m_variableExpressionPtr == variable.getVariableExpressionPtr();
        }

    protected:
        VariableExpressionPtr m_variableExpressionPtr;
    };

}

#endif

