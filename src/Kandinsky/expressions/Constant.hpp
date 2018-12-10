#ifndef KANDINSKY_CONSTANT_HPP_
#define KANDINSKY_CONSTANT_HPP_

#include <Kandinsky/expressions/BaseExpression.hpp>
#include <Kandinsky/expressions/defaultFormatter.hpp>

#include <functional>
#include <sstream>

namespace Kandinsky
{
    class Constant : public BaseExpression
    {
    public:
        Constant(double value) : m_value(value) {}

        void setFormatter(const std::function<std::string(double)>& formatter)
        {
            m_formatter = formatter;
        }

        double evaluate() const
        {
            return m_value;
        }

        virtual BaseExpressionPtr derivative(const std::shared_ptr<VariableExpression>& variable) const;

        virtual void fillVariableSet(std::set<Variable, VariableLessThanComparator>& /*variableSet*/, const BaseExpressionPtr& /*thisSharedPtr*/) const
        {
        }

        virtual std::string toString(bool /*evaluate*/ = false) const
        {
            return m_formatter(m_value);
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
        std::function<std::string(double)> m_formatter = defaultFormatter;
    };

    typedef std::shared_ptr<Constant> ConstantPtr;
}

#endif
