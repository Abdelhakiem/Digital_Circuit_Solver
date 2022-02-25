#include "Gate.h"



void Gate::Set_In1(Node*n)
{
	In1 = n;
}

void Gate::Set_In2(Node* n)
{
	In2 = n;
}

void Gate::Set_Out(Node* n)
{
	Out = n;
}

Node* Gate::Get_In1()
{
	return In1;
}

Node* Gate::Get_In2()
{
	return In2;
}

Node* Gate::Get_Out()
{
	return Out;
}

Gate::~Gate()
{
}
