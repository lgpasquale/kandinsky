#ifndef KANDINSKY_CONSTANT_HPP_
#define KANDINSKY_CONSTANT_HPP_

#include <Kandinsky/expressions/BaseExpression.hpp>

#include <sstream>

namespace Kandinsky
{
    class Constant : public BaseExpression
    {
    public:
        Constant(double value) : m_value(value) {}

        double evaluate() const
        {
            return m_value;
        }

        virtual BaseExpressionPtr derivative(const std::shared_ptr<VariableExpression>& variable) const;

        virtual void fillVariableSet(std::set<Variable, VariableLessThanComparator>& /*variableSet*/, const BaseExpressionPtr& /*thisSharedPtr*/) const
        {
        }

        virtual std::string toString() const
        {
            std::ostringstream valueStream;
            valueStream << m_value;
            return valueStream.str();
        }

        virtual bool isConstant() const
        {
            return true;
        }

        virtual size_t sizeOfInternalNodes() const
        {
            return 0;
        }

        virtual size_t numberOfInternalNodes() const
        {
            return 0;
        }

        virtual size_t numberOfConstants() const
        {
            return 1;
        }

    private:
        double m_value;
    };

    typedef std::shared_ptr<Constant> ConstantPtr;
}

#endif
