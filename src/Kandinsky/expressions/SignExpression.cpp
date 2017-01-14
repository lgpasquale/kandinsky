#include <Kandinsky/expressions/SignExpression.hpp>
#include <Kandinsky/expressions/BaseExpression.tpp>

namespace Kandinsky
{
    BaseExpressionPtr SignExpression::derivative(const VariableExpressionPtr& /*variable*/) const
    {
        return BaseExpression::makePtr(Constant(0));
    }
}

