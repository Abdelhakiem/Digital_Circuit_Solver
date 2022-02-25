#include "My_Vector.h"
template<class type>
My_Vector<type>::My_Vector()
{
    capacity = 10;
    size = 0;
    ptr = new type[capacity];
}
template<class type>
My_Vector<type>::My_Vector(int s)
{
    capacity = 10 + s;
    size = s;
    ptr = new type[capacity];
}
template<class type>
My_Vector<type>::My_Vector(My_Vector<type>& d)
{
    size = d.Get_size();
    capacity = size + 10;
    ptr = new type[capacity];
    for (int i = 0; i < size; i++)
    {
        ptr[i] = d.ptr[i];
    }
}
template<class type>
int My_Vector<type>::Get_size()
{
    return size;
}
template<class type>
void My_Vector<type>::Set_size(int s)
{
    if (s > capacity)
    {
        capacity = s + 10;
        type* temp = new type[capacity];
        for (int i = 0; i < size; i++)
        {
            temp[i] = ptr[i];
        }
        size = s;
        delete[]ptr;
        ptr = temp;
    }
    else
    {
        size = s;
    }
}
template<class type>
void My_Vector<type>::Push_back(type num)
{
    Set_size(size + 1);
    ptr[size - 1] = num;
}
template<class type>
void My_Vector<type>::Insert_element(type num, int p)
{
    Set_size(size + 1);
    //zero based:
    ptr[p] = num;
    for (int i = size - 1; i > p; i--)
    {
        ptr[i] = ptr[i - 1];
    }
    ptr[p] = num;
}
template<class type>
type My_Vector<type>::Get_element(int i)
{
    if (i < size)
    {
        return ptr[i];
    }

}
template<class type>
type& My_Vector<type>::operator[](int i)
{
        return ptr[i];
}
template<class type>
inline My_Vector<type>::~My_Vector()
{
    delete[]ptr;
}
