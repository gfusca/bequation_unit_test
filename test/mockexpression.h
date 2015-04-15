#ifndef _MOCK_EXPRESSION_H
#define _MOCK_EXPRESSION_H

#include "expression.h"
#include "operator.h"

#include <gmock/gmock.h>
#include <string>


class MockExpression : public BooleanExpression {

public:
	MockExpression(BooleanOperator* Operator) : BooleanExpression(Operator) {}
	virtual ~MockExpression() {}
	MOCK_METHOD2(substitute, void(const std::string& ArgIdentifier, bool Value));
	MOCK_METHOD0(evaluate, bool());
	MOCK_CONST_METHOD0(getExpressionAsString, std::string());
};


class MockOperator : public BooleanOperator {

public:
	~MockOperator() {}

	MOCK_METHOD2(substitute, void(const std::string& ArgIdentifier, bool Value));
	MOCK_METHOD0(evaluate, bool());
	MOCK_CONST_METHOD0(getExpressionAsString, std::string());
	MOCK_CONST_METHOD0(getIdentifier, std::string());
	MOCK_METHOD1(addOperator, void(BooleanOperator* Operator));
};

#endif
