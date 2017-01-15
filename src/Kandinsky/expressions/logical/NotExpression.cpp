#include <Kandinsky/expressions/logical/NotExpression.hpp>
#include <Kandinsky/expressions/BaseExpression.tpp>
#include <Kandinsky/expressions/Constant.hpp>

namespace Kandinsky
{
    BaseExpressionPtr NotExpression::derivative(const VariableExpressionPtr& /*variable*/) const
    {
        return makePtr(Constant(0));
    }
}

