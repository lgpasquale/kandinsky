#include <Kandinsky/expressions/Variable.hpp>
#include <Kandinsky/expressions/Expression.hpp>

namespace Kandinsky
{
    std::shared_ptr<BaseExpression> Variable::derivative(const std::shared_ptr<VariableExpression>& variable) const
    {
        return m_variableExpressionPtr->derivative(variable);
    }

    Expression Variable::differentiate(const Variable& variable) const
    {
        return m_variableExpressionPtr->differentiate(variable);
    }
}
