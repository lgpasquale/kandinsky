#ifndef KANDINSKY_VARIABLEEXPRESSION_HPP_
#define KANDINSKY_VARIABLEEXPRESSION_HPP_

#include <Kandinsky/expressions/BaseExpression.hpp>
#include <Kandinsky/expressions/Constant.hpp>

#include <string>

namespace Kandinsky
{
    class VariableExpression : public BaseExpression
    {
    public:
        VariableExpression() : m_value(0), m_name(generateName()) {}
        VariableExpression(double value) : m_value(value), m_name(generateName()) {}
        VariableExpression(const std::string& name, double value = 0) :
                m_value(value), m_name(name) {}

        void setValue(double value)
        {
            m_value = value;
        }

        double getValue() const
        {
            return m_value;
        }

        void setName(const std::string& name)
        {
            m_name = name;
        }

        const std::string& getName() const
        {
            return m_name;
        }

        double evaluate() const
        {
            return m_value;
        }

        virtual std::shared_ptr<BaseExpression> derivative(const std::shared_ptr<VariableExpression>& variable) const;

        virtual std::string print() const
        {
            return m_name;
        }

        bool operator==(const VariableExpression& variable) const
        {
            return this == &variable;
        }

    private:
        static std::string generateName()
        {
            static int count(0);
            return "x_{" + std::to_string(count++) + "}";
        }

        double m_value;
        std::string m_name;
    };

    typedef std::shared_ptr<VariableExpression> VariableExpressionPtr;
}

#endif

