#ifndef __OPERATOR_H__
#define __OPERATOR_H__
#include <vector>
#include <string>
#include <exception>

class BooleanOperator {
	BooleanOperator(const BooleanOperator&);

public:
	BooleanOperator() {}
	virtual ~BooleanOperator() {}
	virtual bool evaluate()=0;	
	virtual std::string getExpressionAsString() const=0;
	virtual void addOperator(BooleanOperator* Operator)=0;
	virtual void substitute(const std::string& ArgumentIdentifier, bool Value)=0;
	virtual std::string getIdentifier()const=0;
};

class BooleanOperatorFactory {

public:
	static BooleanOperator* create(const std::string& Identifier);
};

class BooleanLogicOperator : public BooleanOperator {

public:
	virtual ~BooleanLogicOperator();
	void addOperator(BooleanOperator* Operator);
	virtual bool evaluate()=0;
	virtual void substitute(const std::string& ArgumentIdentifier, bool Value);

protected:
	std::vector<BooleanOperator*> operators_;
};

class BooleanArgument : public BooleanOperator {

public:
	BooleanArgument(const std::string& Identifier);
	bool evaluate();
	virtual std::string getExpressionAsString() const;	
	virtual std::string getIdentifier() const;
	virtual void substitute(const std::string& ArgumentIdentifier, bool Value);
	virtual void addOperator(BooleanOperator* Operator);

private:
	std::string identifier_;
	bool value_;
};

class AndOperator : public BooleanLogicOperator {
public:
	~AndOperator() {}
	bool evaluate();
	virtual std::string getExpressionAsString() const;
	virtual std::string getIdentifier()const;
};

class OrOperator : public BooleanLogicOperator {
public:
	~OrOperator() {}
	bool evaluate();
	virtual std::string getExpressionAsString() const;
	virtual std::string getIdentifier()const;
};

class InvalidOperatorAssignmentException : std::exception {

public:
	InvalidOperatorAssignmentException(const std::string& Message) : msg_(Message) {
	}
	virtual ~InvalidOperatorAssignmentException() throw() {}
	std::string getMessage() {
		return msg_;
	}

protected:
	std::string msg_;
};

#endif	// __OPERATOR_H__
