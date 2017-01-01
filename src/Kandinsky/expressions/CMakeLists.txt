set(${PROJECT_NAME}_HEADERS ${${PROJECT_NAME}_HEADERS}
    expressions/Expression.hpp
    expressions/ExpressionTraits.hpp
    expressions/Constant.hpp
    expressions/Variable.hpp
    expressions/UnaryExpression.hpp
    expressions/BinaryExpression.hpp

    expressions/AdditionExpression.hpp
    expressions/SubtractionExpression.hpp
    expressions/MultiplicationExpression.hpp
    expressions/DivisionExpression.hpp

    expressions/AbsExpression.hpp
    expressions/MinusExpression.hpp

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
    CACHE INTERNAL "")

set(${PROJECT_NAME}_SOURCES ${${PROJECT_NAME}_SOURCES}
    CACHE INTERNAL "")

