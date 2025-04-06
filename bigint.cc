#include "bigint.hh"

#define FULL_TEMPLATE template <int num_blocks, typename blocktype, bool sign_enable>


FULL_TEMPLATE 
void bigint<num_blocks, blocktype, sign_enable>::operator+=(const int val)
{
    blocks[0] += val;

    // check if overflow happened
    if (blocks[0] < (blocks[0] - val)) blocks[1]++;
}

FULL_TEMPLATE 
void bigint<num_blocks, blocktype, sign_enable>::operator-=(const int val)
{
    blocks[0] -= val;

    // check if underflow happened
    if (blocks[0] > (blocks[0] + val)) blocks[1]--;
}




#pragma region CONSTRUCTORS

FULL_TEMPLATE
bigint<num_blocks, blocktype, sign_enable>::bigint(const int val)
{
    blocks = {};
    *(int*)&blocks = val;
}

FULL_TEMPLATE
bigint<num_blocks, blocktype, sign_enable>::bigint(const blocktype val)
{
    blocks = {val};
}





#pragma endregion