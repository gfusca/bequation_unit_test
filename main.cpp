#include <iostream>
#include <string>
#include "expression.h"
#include "expressionparser.h"
/**
 * gCov usage example
 * binary boolean expresion evaluator
 * Usage:
 * bool_eval <bool_expression> <value_1> <value_2> <...> <value_n>
 * @author: Gabriel Fusca
 **/

void print_usage() {
	std::cout << "usage: eval_ <bool_expression> <arg1=value_1> <arg2=value_2> <...> <argn=value_n>" << std::endl;
}

int  main(int argc, char** argv) {
	// at least a expression and a value is needed
	if (argc < 3) {
		print_usage();
		return 1;
	}
	try {
		BooleanExpression* expression = ExpressionParser::parse(argv[1]);
		for (int i = 2; i < argc; ++i) {
			std::string option = std::string(argv[i]);
			std::string identifier = option.substr(0, option.find("="));
			std::string value = option.substr(option.find("=") + 1, option.size() - 1);
			expression->substitute(identifier, value.compare("True") == 0? true : false);
		}
		std::cout << "Expression: " << *expression << "=" << expression->evaluate()<< std::endl;
		
	} catch (...) {
		std::cerr << "Boolean Expression Error, please verify the expression!" << std::endl;
		return 1;
	}
	return 0;
}

