#ifndef __OPERATOR_H__
#define __OPERATOR_H__

class BooleanOperator {
	BooleanOperator(const BooleanOperator&);

public:
	BooleanOperator() {}
	virtual ~BooleanOperator() {}
	virtual bool evaluate()=0;	
	virtual std::string getExpressionAsString()const=0;
};

class BinaryOperator : public BooleanOperator {

public:
	BinaryOperator(BooleanOperator* Left, BooleanOperator* Right);
	virtual ~BinaryOperator();
	virtual bool evaluate()=0;

protected:
	BooleanOperator* left_;
	BooleanOperator* right_;
};

class BooleanArgument : public BooleanOperator {

public:
	BooleanArgument(const std::string& Identifier);
	bool setValue(bool Value);
	bool evaluate();
	virtual std::string getExpressionAsString()const;	

private:
	std::string identifier_;
	bool value_;
};

class AndOperator : public BinaryOperator {
public:
	AndOperator(BooleanOperator* Left, BooleanOperator* Right);
	bool evaluate();
	virtual std::string getExpressionAsString()const;
};
class OrOperator : public BinaryOperator {
public:
	OrOperator(BooleanOperator* Left, BooleanOperator* Right);
	bool evaluate();
	virtual std::string getExpressionAsString()const;
};

#endif	// __OPERATOR_H__
