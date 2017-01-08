#ifndef KANDINSKY_BASEEXPRESSION_HPP_
#define KANDINSKY_BASEEXPRESSION_HPP_

#include <memory>
#include <string>

namespace Kandinsky
{
    class VariableExpression;
    class Variable;
    class Expression;

    class BaseExpression
    {
    public:
        virtual double evaluate() const = 0;
        virtual std::shared_ptr<BaseExpression> derivative(const std::shared_ptr<VariableExpression>& variable) const = 0;
        virtual Expression differentiate(const Variable& variable) const;

        virtual std::string print() const = 0;

        template <class T>
        static std::shared_ptr<BaseExpression> makePtr(const T& arg);
    };

    typedef std::shared_ptr<BaseExpression> BaseExpressionPtr;

    template <>
    std::shared_ptr<BaseExpression> BaseExpression::makePtr<Variable>(const Variable& arg);

    template <>
    std::shared_ptr<BaseExpression> BaseExpression::makePtr<Expression>(const Expression& arg);
}

#endif
