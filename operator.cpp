#include <string>
#include "operator.h"

BinaryOperator::BinaryOperator(BooleanOperator* Left, BooleanOperator* Right) :
															left_(Left), right_(Right) {
}

BinaryOperator::~BinaryOperator() {
	delete left_;
	delete right_;
}

BooleanArgument::BooleanArgument(const std::string& Identifier) : identifier_(Identifier), value_(false) {
}

bool BooleanArgument::setValue(bool Value) {
	value_ = Value;
}

bool BooleanArgument::evaluate() {
	return value_;
}

AndOperator::AndOperator(BooleanOperator* Left, BooleanOperator* Right) : BinaryOperator(Left, Right) {
}

bool AndOperator::evaluate() {
	return left_->evaluate() && right_->evaluate();

}
std::string AndOperator::getExpressionAsString() const {
	std::string expression;
	expression = "And( " + left_->getExpressionAsString() + ", " + right_->getExpressionAsString() + " )";
	return expression;
}

OrOperator::OrOperator(BooleanOperator* Left, BooleanOperator* Right) : BinaryOperator(Left, Right) {
}

bool OrOperator::evaluate() {
	return left_->evaluate() || right_->evaluate();
}

std::string OrOperator::getExpressionAsString() const {
	std::string expression;
	expression = "Or( " + left_->getExpressionAsString() + ", " + right_->getExpressionAsString() + " )";
	return expression;
}

