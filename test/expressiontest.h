#ifndef __EXPRESSION_TEST_H__
#define __EXPRESSION_TEST_H__
#include <gtest/gtest.h>
#include "expressionparser.h"

class ExpressionTest : public testing::Test {

public:
	ExpressionTest();
	void testExpressionParse();
	void testExpressionAsString();
	void testSimpleArgumentExpressionEvaluation();
	void testCaseInsensitiveParser();
	void testParserWithSpaces();
	void testTrueNestedEquation();
	void testFalseNestedEquation();
	void testNestedParenthesisParse();
	// Method required
	void TestBody() {}

protected:
	virtual void SetUp();
	virtual void TearDown();
	ExpressionParser parser_;
};

/** Test definitions **/
TEST_F(ExpressionTest, SimpleExpressionParseTest) {
	ExpressionTest tester;
	tester.testExpressionParse();
}

/** Test definitions **/
TEST_F(ExpressionTest, ExpressionToStringString) {
	ExpressionTest tester;
	tester.testExpressionAsString();
}

/** Test definitions **/
TEST_F(ExpressionTest, SimpleArgumentExpressionEvalTest) {
	ExpressionTest tester;
	tester.testSimpleArgumentExpressionEvaluation();
}

/** Test definitions **/
TEST_F(ExpressionTest, CaseInsensitiveParserTest) {
	ExpressionTest tester;
	tester.testCaseInsensitiveParser();
}

TEST_F(ExpressionTest, ParserWithSpacesTest) {
	ExpressionTest tester;
	tester.testParserWithSpaces();
}

TEST_F(ExpressionTest, TrueNestedEquationTest) {
	ExpressionTest tester;
	tester.testTrueNestedEquation();
}

TEST_F(ExpressionTest, FalseNestedEquationTest) {
	ExpressionTest tester;
	tester.testFalseNestedEquation();
}

TEST_F(ExpressionTest, TestNestedParenthesis) {
	ExpressionTest tester;
	tester.testNestedParenthesisParse();
}
#endif
