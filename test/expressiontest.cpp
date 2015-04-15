#include <string>
#include <gtest/gtest.h>

#include "expressionparser.h"
#include "expressiontest.h"
#include "expression.h"

// #define RUN_FAIL_TEST
	
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

void ExpressionTest::testCaseInsensitiveParser() {
#ifdef RUN_FAIL_TEST
	try {
		std::string expressionstr = "and(a,b)";
		BooleanExpression* expression = ExpressionParser::parse(expressionstr);
		delete expression;
		ASSERT_TRUE(true);
	} catch (...) {
		ASSERT_TRUE(false);
	}
#endif
}

void ExpressionTest::testParserWithSpaces() {
#ifdef RUN_FAIL_TEST
	try {
		std::string expressionstr = "and(a, b)";
		BooleanExpression* expression = ExpressionParser::parse(expressionstr);
		delete expression;
		ASSERT_TRUE(true);
	} catch (...) {
		ASSERT_TRUE(false);
	}
#endif
}

void ExpressionTest::testTrueNestedEquation() {
	try {
		std::string expressionstr = "AND(AND(x,y),OR(b,c))";
		BooleanExpression* expression = ExpressionParser::parse(expressionstr);
		expression->substitute("x", true);
		expression->substitute("y", true);
		expression->substitute("c", true);
		EXPECT_TRUE(expression->evaluate() == true);
		delete expression;
	} catch (...) {
		ASSERT_TRUE(false);
	}

}

void ExpressionTest::testFalseNestedEquation() {
	try {
		std::string expressionstr = "AND(AND(x,y),OR(b,c))";
		BooleanExpression* expression = ExpressionParser::parse(expressionstr);
		expression->substitute("x", true);
		expression->substitute("y", true);
		expression->substitute("c", false);
		expression->substitute("b", false);
		EXPECT_TRUE(expression->evaluate() == false);
		delete expression;
	} catch (...) {
		ASSERT_TRUE(false);
	}

}

void ExpressionTest::testNestedParenthesisParse() {
#ifdef RUN_FAIL_TEST
	try {
		std::string expressionstr = "AND(OR(AND(x,y), OR(a,b)),OR(b,c))";
		BooleanExpression* expression = ExpressionParser::parse(expressionstr);
		expression->substitute("x", true);
		expression->substitute("y", true);
		expression->substitute("c", false);
		expression->substitute("b", false);
		std::cout << *expression << std::endl;
		EXPECT_TRUE(expression->evaluate() == false);
		delete expression;
	} catch (...) {
		ASSERT_TRUE(false);
	}
#endif
}

