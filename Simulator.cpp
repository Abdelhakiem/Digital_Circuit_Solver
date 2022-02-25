#include "Simulator.h"

Simulator::Simulator()
{
}
Simulator::~Simulator()
{
	for (int i = 0; i < GA.size(); i++)
	{
	  delete GA[i];
	}
	for (int i = 0; i < NA.size(); i++)
	{
		delete NA[i];
	}
}

int Simulator::Get_Gate_Size()
{
	return GA.size();
}

int Simulator::Get_Node_Size()
{
	return NA.size();
}

void Simulator::PrintAllNode()
{
    for (size_t i = 0; i < NA.size(); i++)
    {
             cout << NA[i]->Get_Name() << ":" << NA[i]->Get_Value() << endl;

    }
	
}

Gate* Simulator::ADD_GATE(string type)
{
    Gate* ptr = NULL;
    try
    {
       
        if (type == "AND")
        {
            ptr = new AND();
        }
        else if (type == "NAND")
        {
            ptr = new NAND();
        }
        else if (type == "OR")
        {
            ptr = new OR();
        }
        else if (type == "NOR")
        {
            ptr = new NOR();
        }
        else if (type == "XOR")
        {
            ptr = new XOR();
        }

        else if (type == "XNOR")
        {
            ptr = new XNOR();
        }
        else
        {
            throw(type);
        }
        
    }
    catch (string s)
    {
        cout << "there is no Gate with name: " << s << endl;
    }
    GA.push_back(ptr);
    return ptr;

}

Node* Simulator::ADD_Node(string n)
{
    Node* node;
	node = new Node(n);
    NA.push_back(node);
	return node;
}

Node* Simulator::Find_Node(string n)
{
	for (int i = 0; i < Get_Node_Size(); i++)
	{
		if (n == NA[i]->Get_Name())
		{
			return NA[i];
		}
	}
	return nullptr;
}

Node* Simulator::AddOrFind(string n)
{
	Node* node = Find_Node(n);
	if (node != nullptr)
	{
		return node;
	}
return ADD_Node(n);
}

void Simulator:: Load(string path)
{

    ifstream file;
    file.open(path);

    
       
        string s, gate_type, input1, input2, output;
        while (!file.eof())
        {

            file >> s;
            if (s == "SET")
            {
                string N, v;
                file >> N >> v;
                AddOrFind(N)->Set_Value(stoi(v));
            }
            else if (s == "SIM")
            {
                Sim();
            }
            else if (s == "OUT")
            {
                string c;
                file >> c;
                if (c == "ALL")
                {
                    PrintAllNode();
                }
                else
                {
                    AddOrFind(c)->Print_All();
                }

            }
            else
            {
                gate_type = s;
                file >> input1 >> input2 >> output;

                Gate* gate = ADD_GATE(gate_type);
                gate->Set_In1(AddOrFind(input1));
                gate->Set_In2(AddOrFind(input2));
                gate->Set_Out(AddOrFind(output));

            }

    }

    file.close();
  }

void Simulator::Sim()
{
    for (int i = 0; i < GA.size(); i++)
    {
        for (int j = 0; j < GA.size(); j++)
        {
            GA[j]->Calc_Out();
        }
        
    }
}
