#include <string>
#include <gtest/gtest.h>

#include "expressionparser.h"
#include "expressiontest.h"
#include "expression.h"
	
ExpressionTest::ExpressionTest() {
}

void ExpressionTest::SetUp() {
}
void ExpressionTest::TearDown() {
}

void ExpressionTest::testExpressionParse() {
	std::string expressionstr = "AND(a,b)";
	try {
		BooleanExpression* expression = ExpressionParser::parse(expressionstr);
		delete expression;
		ASSERT_TRUE(true);
	} catch (ExpressionParseException& e) {
		//TEST_FAIL("Parse Error") 
		ASSERT_TRUE(false);
	}
}

void ExpressionTest::testExpressionAsString() {
	try {
		std::string expressionstr = "AND(a,b)";
		std::string expression_expected = "And(False, False)";
		BooleanExpression* expression = ExpressionParser::parse(expressionstr);
		EXPECT_STREQ(expression->getExpressionAsString().c_str(), expression_expected.c_str());
		delete expression;
	} catch (...) {
		ASSERT_TRUE(false);
	}
}

void ExpressionTest::testSimpleArgumentExpressionEvaluation() {
	try {
		std::string expressionstr = "A";
		BooleanExpression* expression = ExpressionParser::parse(expressionstr);
		expression->substitute(expressionstr, true);
		ASSERT_TRUE(expression->evaluate() == true);
		delete expression;
	} catch (...) {
		ASSERT_TRUE(false);
	}
}

