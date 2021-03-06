#ifndef __FUDANDNN_ABSTRACTCOMPONENT_H
#define __FUDANDNN_ABSTRACTCOMPONENT_H
#include "utils.h"
#include "Matrix.h"

class AbstractComponent
{
public:
	void setNum(size_t num);
	size_t getNum();
	void setVisualValue(vector<shared_ptr<AbstractMatrix>> visualValue);
	vector<shared_ptr<AbstractMatrix>> getVisualValue();
	vector<shared_ptr<AbstractMatrix>> getHiddenValue();
	void setHiddenGradient(vector<shared_ptr<AbstractMatrix>> hiddenGradient);
	vector<shared_ptr<AbstractMatrix>> getVisualGradient();
	vector<shared_ptr<AbstractMatrix>> getHiddenGradient();
	virtual void compute() {};
	virtual void calculate() {};
	virtual void gradient() {};
	virtual void update() {};
	virtual void regularize() {};
	virtual void writeSelf(string) {};
	virtual void readSelf(string) {};
	virtual string getComponentName() { return nullptr; };
	void setVisualRow(size_t visualRow);
	size_t getVisualRow();
	void setVisualColumn(size_t visualColumn);
	size_t getVisualColumn();
	void setHiddenRow(size_t hiddenRow);
	size_t getHiddenRow();
	void setHiddenColumn(size_t hiddenColumn);
	size_t getHiddenColumn();
	virtual size_t calculateHiddenSize(){ return 0; };
	void setHiddenColumn();
	virtual void initialization(){};
	virtual ~AbstractComponent() {};

protected:
	vector<shared_ptr<AbstractMatrix>> visualValue;
	vector<shared_ptr<AbstractMatrix>> hiddenValue;
	vector<shared_ptr<AbstractMatrix>> visualGradient;
	vector<shared_ptr<AbstractMatrix>> hiddenGradient;

	size_t num;
	size_t visualRow = 1;
	size_t visualColumn = 1;
	size_t hiddenRow = 1;
	size_t hiddenColumn = 1;
};
#endif