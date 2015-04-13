#include "expressionparser.h"
#include "operator.h"
#include "expression.h"
#include <string>
#include <sstream>
#include <algorithm>

/** Recursive parser **/
BooleanOperator* do_parse(std::string& Expression) {
	size_t begin = Expression.find_first_of("(");
	size_t end = Expression.find_last_of(")");
	std::string operator_identifier = Expression.substr(0, begin);
	BooleanOperator* boperator = BooleanOperatorFactory::create(operator_identifier);
	std::string arguments = Expression.substr(begin + 1, end - begin - 1);
	std::string token, jointoken;
	std::stringstream ss(arguments);
	while(arguments.find(",") != std::string::npos && std::getline(ss, token, ',')) {
		if (token.find("(") != std::string::npos || token.find(")") != std::string::npos)
			jointoken += token + ",";
		if (token.find(")") != std::string::npos && !jointoken.empty()) {
			token = jointoken.substr(0, jointoken.size() - 2);
			jointoken.clear();
		} else if (!jointoken.empty())
			token.clear();
		
		if (!token.empty()) {
			BooleanOperator* nest_operator = do_parse(token);
			boperator->addOperator(nest_operator);
		}
	}
	return boperator;
}

BooleanExpression* ExpressionParser::parse(const std::string& Expression) {
	std::string exprcopy = Expression;
	return new BooleanExpression(do_parse(exprcopy));
}

