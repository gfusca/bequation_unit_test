// #include "expressiontest.h"
#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include "mockexpression.h"

using testing::ReturnNew;
using testing::Return;

TEST(MockTestCase, MockTestString) {
	std::string eq = "AND(OR(a,b),AND(c,d))";
	MockOperator *op = new MockOperator;
	MockExpression expression(op);
	EXPECT_CALL(expression, getExpressionAsString()).WillOnce(Return(eq));
	EXPECT_STREQ(eq.c_str(), expression.getExpressionAsString().c_str());
}

TEST(MockTestCase, MockTestEvaluation) {
	MockOperator *op = new MockOperator;
	MockExpression expression(op);
	EXPECT_CALL(expression, evaluate()).WillOnce(Return(true));
	EXPECT_EQ(true, expression.evaluate());
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
  	testing::InitGoogleMock(&argc, argv);
  	return RUN_ALL_TESTS();	
}
