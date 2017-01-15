set(${PROJECT_NAME}_HEADERS ${${PROJECT_NAME}_HEADERS}
    expressions/logical/AndExpression.hpp
    expressions/logical/OrExpression.hpp
    expressions/logical/NotExpression.hpp
    CACHE INTERNAL "")

set(${PROJECT_NAME}_SOURCES ${${PROJECT_NAME}_SOURCES}
    expressions/logical/AndExpression.cpp
    expressions/logical/OrExpression.cpp
    expressions/logical/NotExpression.cpp
    CACHE INTERNAL "")

