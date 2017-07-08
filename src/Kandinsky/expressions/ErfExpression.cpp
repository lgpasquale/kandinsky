#include <Kandinsky/expressions/ErfExpression.hpp>
#include <Kandinsky/expressions/MultiplicationExpression.hpp>
#include <Kandinsky/expressions/MinusExpression.hpp>
#include <Kandinsky/expressions/ExponentialExpression.hpp>
#include <Kandinsky/expressions/DivisionExpression.hpp>
#include <Kandinsky/expressions/BaseExpression.tpp>
#ifndef M_PI
#define M_PI std::acos(-1.0)
#endif
namespace Kandinsky
{
    BaseExpressionPtr ErfExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(2.0*exp(-1.0*m_arg*m_arg)/std::sqrt(M_PI) * m_arg->derivative(variable));
    }
}