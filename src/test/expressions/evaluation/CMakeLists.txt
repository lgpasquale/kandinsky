add_project_test_executable(constant_evaluation_test ConstantEvaluationTest.cpp
    TEST_NAME ConstantEvaluationTest)

add_project_test_executable(variable_evaluation_test VariableEvaluationTest.cpp
    TEST_NAME VariableEvaluationTest)

add_project_test_executable(addition_evaluation_test AdditionEvaluationTest.cpp
    TEST_NAME AdditionEvaluationTest)

add_project_test_executable(subtraction_evaluation_test SubtractionEvaluationTest.cpp
    TEST_NAME SubtractionEvaluationTest)

add_project_test_executable(multiplication_evaluation_test MultiplicationEvaluationTest.cpp
    TEST_NAME MultiplicationEvaluationTest)

add_project_test_executable(division_evaluation_test DivisionEvaluationTest.cpp
    TEST_NAME DivisionEvaluationTest)

add_project_test_executable(abs_evaluation_test AbsEvaluationTest.cpp
    TEST_NAME AbsEvaluationTest)

add_project_test_executable(composite_evaluation_test CompositeEvaluationTest.cpp
    TEST_NAME CompositeEvaluationTest)

add_project_test_executable(power_evaluation_test PowerEvaluationTest.cpp
    TEST_NAME PowerEvaluationTest)

add_project_test_executable(square_root_evaluation_test SquareRootEvaluationTest.cpp
    TEST_NAME SquareRootEvaluationTest)

add_project_test_executable(natural_logarithm_evaluation_test NaturalLogarithmEvaluationTest.cpp
    TEST_NAME NaturalLogarithmEvaluationTest)

add_project_test_executable(exponential_evaluation_test ExponentialEvaluationTest.cpp
    TEST_NAME ExponentialEvaluationTest)

add_project_test_executable(erf_evaluation_test ErfEvaluationTest.cpp
    TEST_NAME ErfEvaluationTest)
	
add_project_test_executable(sine_evaluation_test SineEvaluationTest.cpp
    TEST_NAME SineEvaluationTest)

add_project_test_executable(cosine_evaluation_test CosineEvaluationTest.cpp
    TEST_NAME CosineEvaluationTest)

add_project_test_executable(tangent_evaluation_test TangentEvaluationTest.cpp
    TEST_NAME TangentEvaluationTest)

add_project_test_executable(arcsine_evaluation_test ArcSineEvaluationTest.cpp
    TEST_NAME ArcSineEvaluationTest)

add_project_test_executable(arccosine_evaluation_test ArcCosineEvaluationTest.cpp
    TEST_NAME ArcCosineEvaluationTest)

add_project_test_executable(arctangent_evaluation_test ArcTangentEvaluationTest.cpp
    TEST_NAME ArcTangentEvaluationTest)

add_project_test_executable(if_then_else_evaluation_test IfThenElseEvaluationTest.cpp
    TEST_NAME IfThenElseEvaluationTest)

add_subdirectory(comparison)
add_subdirectory(logical)

