#ifndef __EXPRESSION_PARSER_H__
#define __EXPRESSION_PARSER_H__

#include <string>

class BooleanExpression;

class ExpressionParser {

public:
	static BooleanExpression* parse(const std::string& Expression);
};
#endif
