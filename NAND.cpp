#include "NAND.h"
void NAND::Calc_Out()
{
    if ((In1->Get_Value() == 1) && (In2->Get_Value() == 1))
    {
        Out->Set_Value(0);
    }
    else
    {
        Out->Set_Value(1);
    }


}