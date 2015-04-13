#include <string>
#include "expression.h"
#include "operator.h"

BooleanExpression::BooleanExpression(BooleanOperator* Operator) : operator_(Operator) {
}

BooleanExpression::~BooleanExpression() {
	delete operator_;
}

void BooleanExpression::substitute(const std::string& ArgumentIdentifier, bool Value) {
	operator_->substitute(ArgumentIdentifier, Value);
}

bool BooleanExpression::evaluate() {
	return operator_->evaluate();
}

BooleanExpression* BooleanExpression::Create(const std::string& Expression) {
	throw ExpressionParseException("Error parsing expression " + Expression);
	return NULL;
}
	
std::string BooleanExpression::getExpressionAsString() const {
	return operator_->getExpressionAsString();
}

