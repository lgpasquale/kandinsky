#ifndef KANDINSKY_EXPRESSION_HPP_
#define KANDINSKY_EXPRESSION_HPP_

#include <Kandinsky/expressions/BaseExpression.hpp>
#include <Kandinsky/expressions/Variable.hpp>

#include <map>

namespace Kandinsky
{
    class Expression
    {
    public:
        template <class ArgT>
        Expression(const ArgT& arg) : m_baseExpressionPtr(BaseExpression::makePtr(arg)) {}

        template <class ArgT>
        Expression(const ArgT&& arg) : m_baseExpressionPtr(BaseExpression::makePtr(arg)) {}

        Expression() : Expression(Constant(0)) {}

        template <class ArgT>
        Expression& operator=(const ArgT& arg)
        {
            m_baseExpressionPtr = BaseExpression::makePtr(arg);
            return *this;
        }

        template <class ArgT>
        Expression& operator=(const ArgT&& arg)
        {
            m_baseExpressionPtr = BaseExpression::makePtr(arg);
            return *this;
        }

        double evaluate() const
        {
            return m_baseExpressionPtr->evaluate();
        }

        std::shared_ptr<BaseExpression> derivative(const std::shared_ptr<VariableExpression>& variable) const
        {
            return m_baseExpressionPtr->derivative(variable);
        }

        Expression differentiate(const Variable& variable) const
        {
            return m_baseExpressionPtr->differentiate(variable);
        }

        virtual std::set<Variable, VariableLessThanComparator> variables() const
        {
            return m_baseExpressionPtr->variables(m_baseExpressionPtr);
        }

        virtual std::map<Variable, Expression, VariableLessThanComparator> derivatives() const;

        virtual std::string toString() const
        {
            return m_baseExpressionPtr->toString();
        }

        BaseExpressionPtr getBaseExpressionPtr() const
        {
            return m_baseExpressionPtr;
        }

        virtual size_t sizeOfAllNodes() const
        {
            return m_baseExpressionPtr->sizeOfAllNodes(m_baseExpressionPtr);
        }

        virtual size_t numberOfInternalNodes() const
        {
            return  m_baseExpressionPtr->numberOfInternalNodes();
        }

        virtual size_t numberOfConstants() const
        {
            return m_baseExpressionPtr->numberOfConstants();
        }

    protected:
        BaseExpressionPtr m_baseExpressionPtr;
    };

    std::ostream& operator<< (std::ostream& stream, const Expression& expression);
}

#endif
