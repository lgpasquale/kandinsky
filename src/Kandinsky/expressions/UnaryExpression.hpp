#ifndef KANDINSKY_UNARYEXPRESSION_HPP_
#define KANDINSKY_UNARYEXPRESSION_HPP_

#include <Kandinsky/expressions/BaseExpression.hpp>
#include <Kandinsky/expressions/ExpressionTraits.hpp>

namespace Kandinsky
{
    class UnaryExpression : public BaseExpression
    {
    public:
        UnaryExpression(const BaseExpressionPtr& arg)
            : m_arg(arg) {}

        virtual void fillVariableSet(std::set<Variable, VariableLessThanComparator>& variableSet, const BaseExpressionPtr& /*thisSharedPtr*/) const
        {
            m_arg->fillVariableSet(variableSet, m_arg);
        }

        virtual size_t sizeOfInternalNodes() const
        {
            return sizeof(*this) + m_arg->sizeOfInternalNodes();
        }

        virtual size_t numberOfInternalNodes() const
        {
            return 1 + m_arg->numberOfInternalNodes();
        }

        virtual size_t numberOfConstants() const
        {
            return m_arg->numberOfConstants();
        }

    protected:
        BaseExpressionPtr m_arg;
    };
}

#endif
