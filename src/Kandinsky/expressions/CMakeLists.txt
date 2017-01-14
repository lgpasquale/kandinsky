set(${PROJECT_NAME}_HEADERS ${${PROJECT_NAME}_HEADERS}
    expressions/BaseExpression.hpp
    expressions/ExpressionTraits.hpp
    expressions/Constant.hpp
    expressions/VariableExpression.hpp
    expressions/Variable.hpp
    expressions/Expression.hpp
    expressions/UnaryExpression.hpp
    expressions/BinaryExpression.hpp

    expressions/AdditionExpression.hpp
    expressions/SubtractionExpression.hpp
    expressions/MultiplicationExpression.hpp
    expressions/DivisionExpression.hpp

    expressions/MinusExpression.hpp
    expressions/SignExpression.hpp
    expressions/AbsExpression.hpp

    expressions/ExponentialExpression.hpp
    expressions/NaturalLogarithmExpression.hpp

    expressions/PowerExpression.hpp
    expressions/SquareRootExpression.hpp

    expressions/SineExpression.hpp
    expressions/CosineExpression.hpp
    expressions/TangentExpression.hpp
    expressions/ArcSineExpression.hpp
    expressions/ArcCosineExpression.hpp
    expressions/ArcTangentExpression.hpp

    expressions/BaseExpression.tpp
    CACHE INTERNAL "")

set(${PROJECT_NAME}_SOURCES ${${PROJECT_NAME}_SOURCES}
    expressions/BaseExpression.cpp
    expressions/Constant.cpp
    expressions/VariableExpression.cpp
    expressions/Variable.cpp
    expressions/Expression.cpp

    expressions/AdditionExpression.cpp
    expressions/SubtractionExpression.cpp
    expressions/MultiplicationExpression.cpp
    expressions/DivisionExpression.cpp

    expressions/MinusExpression.cpp
    expressions/SignExpression.cpp
    expressions/AbsExpression.cpp

    expressions/ExponentialExpression.cpp
    expressions/NaturalLogarithmExpression.cpp

    expressions/PowerExpression.cpp
    expressions/SquareRootExpression.cpp

    expressions/SineExpression.cpp
    expressions/CosineExpression.cpp
    expressions/TangentExpression.cpp
    expressions/ArcSineExpression.cpp
    expressions/ArcCosineExpression.cpp
    expressions/ArcTangentExpression.cpp
    CACHE INTERNAL "")

