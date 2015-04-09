#ifndef __OPERATOR_H__
#define __OPERATOR_H__

class BooleanOperator {
	BooleanOperator(const BooleanOperator&);

public:
	BooleanOperator() {}
	virtual ~BooleanOperator() {}
	virtual bool evaluate()=0;	
	virtual std::string getExpressionAsString() const=0;
	virtual void substitute(const std::string& ArgumentIdentifier, bool Value)=0;
	virtual std::string getIdentifier()const=0;
};

class BooleanOperatorFactory {

public:
	static BooleanOperator* Create(std::string& Expression);
};

class BinaryOperator : public BooleanOperator {

public:
	BinaryOperator(BooleanOperator* Left, BooleanOperator* Right);
	virtual ~BinaryOperator();
	virtual bool evaluate()=0;
	virtual void substitute(const std::string& ArgumentIdentifier, bool Value);

protected:
	BooleanOperator* left_;
	BooleanOperator* right_;
};

class BooleanArgument : public BooleanOperator {

public:
	BooleanArgument(const std::string& Identifier);
	bool evaluate();
	virtual std::string getExpressionAsString() const;	
	virtual std::string getIdentifier() const;
	virtual void substitute(const std::string& ArgumentIdentifier, bool Value);

private:
	std::string identifier_;
	bool value_;
};

class AndOperator : public BinaryOperator {
public:
	AndOperator(BooleanOperator* Left, BooleanOperator* Right);
	~AndOperator() {}
	bool evaluate();
	virtual std::string getExpressionAsString() const;
	virtual std::string getIdentifier()const;
};

class OrOperator : public BinaryOperator {
public:
	OrOperator(BooleanOperator* Left, BooleanOperator* Right);
	~OrOperator() {}
	bool evaluate();
	virtual std::string getExpressionAsString() const;
	virtual std::string getIdentifier()const;
};

#endif	// __OPERATOR_H__
