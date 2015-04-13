#include <string>
#include "operator.h"
#include <algorithm>


void clean_identifier(std::string& Identifier) {
	Identifier.erase(std::remove(Identifier.begin(), Identifier.end(), ')'), Identifier.end());
	Identifier.erase(std::remove(Identifier.begin(), Identifier.end(), '('), Identifier.end());
	Identifier.erase(std::remove(Identifier.begin(), Identifier.end(), ','), Identifier.end());
}

BooleanOperator* BooleanOperatorFactory::create(const std::string& Identifier) {
	if (Identifier.compare("AND") == 0)
		return new AndOperator;
	if (Identifier.compare("OR") == 0)
		return new OrOperator;
	return new BooleanArgument(Identifier);
}

BooleanLogicOperator::~BooleanLogicOperator() {
	for (size_t i = 0; i < operators_.size(); ++i)
		delete operators_[i];
}

void BooleanLogicOperator::substitute(const std::string& ArgumentIdentifier, bool Value) {
	for (size_t i = 0; i < operators_.size(); ++i) {
		operators_[i]->substitute(ArgumentIdentifier, Value);
	}
}
void BooleanLogicOperator::addOperator(BooleanOperator* Operator) {
	operators_.push_back(Operator);
}

BooleanArgument::BooleanArgument(const std::string& Identifier) :
											identifier_(Identifier), value_(false) {
	clean_identifier(identifier_);
}

void BooleanArgument::substitute(const std::string& ArgumentIdentifier, bool Value) {
	if (ArgumentIdentifier.compare(identifier_) == 0) {
		value_ = Value;
	}
}

bool BooleanArgument::evaluate() {
	return value_;
}

std::string BooleanArgument::getExpressionAsString()const {
	return value_ ? "True" : "False";
}

std::string BooleanArgument::getIdentifier()const {
	return identifier_;
}

void BooleanArgument::addOperator(BooleanOperator* Operator) {
	throw InvalidOperatorAssignmentException("Boolean arguments doesnt admit other operators!"); 
}

bool AndOperator::evaluate() {
	bool result = true;
	for (size_t i = 0; i < operators_.size(); ++i)
		result &= operators_[i]->evaluate();
	return result;

}
std::string AndOperator::getExpressionAsString() const {
	std::string expression;
	expression = "And(";
	for (size_t i = 0; i < operators_.size(); ++i)
	 	expression += operators_[i]->getExpressionAsString() + ", ";
	expression = expression.substr(0, expression.size()-2);
	expression += ")";
	return expression;
}

std::string AndOperator::getIdentifier()const {
	return "and";
}

bool OrOperator::evaluate() {
	bool result = false;
	for (size_t i = 0; i < operators_.size(); ++i)
		result |= operators_[i]->evaluate();
	return result;
}

std::string OrOperator::getExpressionAsString() const {
	std::string expression;
	expression = "Or(";
	for (size_t i = 0; i < operators_.size(); ++i)
	 	expression += operators_[i]->getExpressionAsString() + ", ";
	expression = expression.substr(0, expression.size()-2);
	expression += ")";
	return expression;
}

std::string OrOperator::getIdentifier()const {
	return "or";
}

