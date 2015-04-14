#ifndef __EXPRESSION_TEST_H__
#define __EXPRESSION_TEST_H__
#include <cpptest.h>
#include <gtest/gtest.h>

class ExpressionTest : public testing::Test {

public:
	ExpressionTest();
	void testExpressionParse();
	void testExpressionAsString();
	void testSimpleArgumentExpressionEvaluation();
	void TestBody() {}
protected:
	virtual void SetUp();
	virtual void TearDown();
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
#endif
