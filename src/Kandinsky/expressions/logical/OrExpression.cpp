#include <Kandinsky/expressions/logical/OrExpression.hpp>
#include <Kandinsky/expressions/BaseExpression.tpp>
#include <Kandinsky/expressions/Constant.hpp>

namespace Kandinsky
{
    BaseExpressionPtr OrExpression::derivative(const VariableExpressionPtr& /*variable*/) const
    {
        return makePtr(Constant(0));
    }
}

