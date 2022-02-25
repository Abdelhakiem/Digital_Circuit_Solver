#include "NOR.h"
void NOR::Calc_Out()
{
    if ((In1->Get_Value() == 0) || (In2->Get_Value() == 0))
    {
        Out->Set_Value(1);
    }
    else
    {
        Out->Set_Value(0);
    }


}