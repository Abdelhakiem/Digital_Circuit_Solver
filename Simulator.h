#pragma once
#include "Gate.h"
#include "AND.h"
#include "OR.h"
#include "NAND.h"
#include "NOR.h"
#include "XOR.h"
#include "XNOR.h"
#include <string>
#include "My_Vector.h"
#include <fstream>
#include<vector>

class Simulator
{
private:
vector<Gate*> GA;
vector<Node*> NA;

public:
	Simulator();
	~Simulator();
	int Get_Gate_Size();
	int Get_Node_Size();

	Gate* ADD_GATE(string type);

	Node* ADD_Node(string n);
	Node* Find_Node(string n);
	Node* AddOrFind(string n);

	void Load(string path);

	void Sim();

	void PrintAllNode();
};

