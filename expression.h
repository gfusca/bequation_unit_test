#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__

#include <string>

class BooleanExpression {
	BooleanExpression(const std::string& BooleanExpression);

public:
	void substitute(const std::string& ArgumentIdentifier, bool Value);
	bool evaluate();
	std::string getExpressionAsString()const;
	friend std::ostream& operator<< (std::ostream& stream, const BooleanExpression& Expression) {
		stream << Expression.getExpressionAsString();
		return stream;
	}
	static BooleanExpression* Create(const std::string& Expression);
};

#endif	// __EXPRESSION_H__
