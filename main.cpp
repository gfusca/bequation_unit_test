#include <iostream>
/**
 * gCov usage example
 * Boolean expresion evaluator
 * Usage:
 * bool_eval bool_expression value_1 value_2 ... value_n
 * @author: Gabriel Fusca
 **/

void print_usage() {
	std::cout << "usage: eval_ bool_expression value_1 value_2 ... value_n" << std::endl;
}
int  main(int argc, char** argv) {
	if (argc <= 1) {
		print_usage();
		return 1;
	}
	return 0;
}
