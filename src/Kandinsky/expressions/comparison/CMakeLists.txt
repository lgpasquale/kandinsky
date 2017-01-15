set(${PROJECT_NAME}_HEADERS ${${PROJECT_NAME}_HEADERS}
    expressions/comparison/EqualExpression.hpp
    expressions/comparison/NotEqualExpression.hpp
    expressions/comparison/LessExpression.hpp
    expressions/comparison/LessEqualExpression.hpp
    expressions/comparison/GreaterExpression.hpp
    expressions/comparison/GreaterEqualExpression.hpp
    CACHE INTERNAL "")

set(${PROJECT_NAME}_SOURCES ${${PROJECT_NAME}_SOURCES}
    expressions/comparison/EqualExpression.cpp
    expressions/comparison/NotEqualExpression.cpp
    expressions/comparison/LessExpression.cpp
    expressions/comparison/LessEqualExpression.cpp
    expressions/comparison/GreaterExpression.cpp
    expressions/comparison/GreaterEqualExpression.cpp
    CACHE INTERNAL "")

