#pragma once
template<class type>
class My_Vector
{
private:
    type* ptr;
    int size;
    int capacity;
public:
    My_Vector();
    My_Vector(int s);
    My_Vector(My_Vector<type>& d);
    int Get_size();
    void Set_size(int s);
    void Push_back(type num);
    void Insert_element(type num, int p);
    type Get_element(int i);
    type& operator [](int i);
    ~My_Vector();

};


