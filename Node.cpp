#include "Node.h"
Node::Node()
{
	Name = "";
	value = 0;
}
Node::Node(string N)
{
	Name = N;
	value = 0;
}
Node::Node(string N, short v)
{
	Name = N;
	value = v;
}

void Node::Set_Name(string N)
{
		Name = N;
}

void Node::Set_Value(short v)
{
		value = v;
}

string Node::Get_Name()
{
 return Name; 
}

short Node::Get_Value()
{
	return value;
}

void Node::Print_All()
{
	cout << "Name of node= " << Get_Name() << " , value= " << Get_Value() << endl;
}
