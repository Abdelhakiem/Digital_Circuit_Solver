#ifndef NODE_H
#define NODE_H


#include <string>
#include <iostream>
using namespace std;
# define endl "\n"
class Node
{
private:

	string Name;
	short value;
public:
	Node();
	Node(string N);
	Node(string N, short v);
	void Set_Name(string N);
	void Set_Value(short v);
	
	string Get_Name();
	short Get_Value();
	void Print_All();
};

#endif 