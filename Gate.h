#pragma once
#include "Node.h"

class Gate
{
protected:

	Node* In1; Node* In2; Node* Out;

public:

	void Set_In1(Node* n);
	void Set_In2(Node* n);
	void Set_Out(Node* n);
	Node* Get_In1();
	Node* Get_In2();
	Node* Get_Out();

	virtual void Calc_Out()=0;
	~Gate();
};

