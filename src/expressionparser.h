#ifndef __EXPRESSION_PARSER_H__
#define __EXPRESSION_PARSER_H__

#include <string>

class BooleanExpression;

class ExpressionParser {

public:
	BooleanExpression* parse(const std::string& Expression);
};
#endif
