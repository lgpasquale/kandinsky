#ifndef KANDINSKY_BASEEXPRESSION_HPP_
#define KANDINSKY_BASEEXPRESSION_HPP_

#include <memory>
#include <set>
#include <string>

namespace Kandinsky
{
    class VariableExpression;
    class Variable;
    class Expression;

    struct VariableLessThanComparator
    {
        bool operator()(const Variable& variable1, const Variable& variable2) const;
    };

    class BaseExpression
    {
    public:
        virtual double evaluate() const = 0;

        virtual std::shared_ptr<BaseExpression> derivative(const std::shared_ptr<VariableExpression>& variable) const = 0;

        virtual Expression differentiate(const Variable& variable) const;

        virtual std::set<Variable, VariableLessThanComparator> variables(const std::shared_ptr<BaseExpression>& thisSharedPtr) const;

        virtual void fillVariableSet(std::set<Variable, VariableLessThanComparator>& variableSet, const std::shared_ptr<BaseExpression>& thisSharedPtr) const = 0;

        virtual std::string toString(bool evaluate = false) const = 0;

        virtual bool isConstant() const
        {
            return false;
        }

        template <class T>
        static std::shared_ptr<BaseExpression> makePtr(const T& arg);

        virtual size_t sizeOfInternalNodes() const
        {
            return sizeof(*this);
        }

        virtual size_t numberOfInternalNodes() const
        {
            return 0;
        }

        virtual size_t numberOfConstants() const
        {
            return 0;
        }

        virtual size_t sizeOfAllNodes(
            const std::shared_ptr<BaseExpression>& thisSharedPtr) const;

    protected:
    };

    typedef std::shared_ptr<BaseExpression> BaseExpressionPtr;

    template <>
    std::shared_ptr<BaseExpression> BaseExpression::makePtr<Variable>(const Variable& arg);

    template <>
    std::shared_ptr<BaseExpression> BaseExpression::makePtr<Expression>(const Expression& arg);
}

#endif
