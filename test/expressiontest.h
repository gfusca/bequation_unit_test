#ifndef __EXPRESSION_TEST_H__
#define __EXPRESSION_TEST_H__
#include <cpptest.h>

class ExpressionTest : public Test::Suite {

public:
	ExpressionTest();
	void testExpressionParse();
	void testExpressionAsString();
	void testSimpleArgumentExpressionEvaluation();

protected:
	virtual void setup();
	virtual void tear_down();
};
#endif
