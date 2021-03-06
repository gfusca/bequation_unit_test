#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__
#include <ostream>
#include <string>
#include <exception>

class BooleanOperator;

class BooleanExpression {
	BooleanExpression(const std::string& BooleanExpression);

public:
	explicit BooleanExpression(BooleanOperator* Operator);
	virtual ~BooleanExpression();
	virtual void substitute(const std::string& ArgumentIdentifier, bool Value);
	virtual bool evaluate();
	virtual std::string getExpressionAsString()const;
	friend std::ostream& operator<< (std::ostream& stream, const BooleanExpression& Expression) {
		stream << Expression.getExpressionAsString();
		return stream;
	}
	static BooleanExpression* Create(const std::string& Expression);

private:
	BooleanOperator* operator_;
};

class ExpressionParseException : std::exception {

public:
	explicit ExpressionParseException(const std::string& Message) : msg_(Message) {
	}
	virtual ~ExpressionParseException() throw() {}
	std::string getMessage() {
		return msg_;
	}

protected:
	std::string msg_;
};
#endif	// __EXPRESSION_H__
