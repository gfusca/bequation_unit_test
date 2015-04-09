#include <string>

#include "expressiontest.h"
#include "expression.h"
	
ExpressionTest::ExpressionTest() {
	TEST_ADD(ExpressionTest::testExpressionParse)
	TEST_ADD(ExpressionTest::testExpressionAsString)
	TEST_ADD(ExpressionTest::testSimpleArgumentExpressionEvaluation)
}

void ExpressionTest::setup() {
}
void ExpressionTest::tear_down() {
}

void ExpressionTest::testExpressionParse() {
	std::string expressionstr = "AND(a,b)";
	try {
		BooleanExpression* expression = BooleanExpression::Create(expressionstr);
		delete expression;
	} catch (ExpressionParseException& e) {
		TEST_FAIL("Parse Error") 
	}
}

void ExpressionTest::testExpressionAsString() {
	try {
		std::string expressionstr = "AND(a,b)";
		BooleanExpression* expression = BooleanExpression::Create(expressionstr);
		TEST_ASSERT(expression->getExpressionAsString().compare(expressionstr) == 0)
		delete expression;
	} catch (...) {
		TEST_FAIL("Fail!")
	}
}

void ExpressionTest::testSimpleArgumentExpressionEvaluation() {
	try {
		std::string expressionstr = "A";
		BooleanExpression* expression = BooleanExpression::Create(expressionstr);
		expression->substitute(expressionstr, true);
		TEST_ASSERT(expression->evaluate() == true)
		delete expression;
	} catch (...) {
		TEST_FAIL("Fail!")
	}
}

