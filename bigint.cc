#include "bigint.hh"

#define FULL_TEMPLATE template <int num_blocks, typename block_t, bool sign_enable>


FULL_TEMPLATE 
void bigint<num_blocks, block_t, sign_enable>::operator+=(const block_t val)
{
    blocks[0] += val;

    // check if overflow happened
    if (blocks[0] < (blocks[0] - val)) blocks[1]++;
}

FULL_TEMPLATE
void bigint<num_blocks, block_t, sign_enable>::operator+=(const bigint<num_blocks, block_t, sign_enable> val)
{
    for (int i = 0 ; i < num_blocks - 1 ; i++)
    {
        blocks[i] += val;

        if(blocks[i] < (blocks[0] - val)) blocks[i + 1]++;
    }
}

FULL_TEMPLATE 
void bigint<num_blocks, block_t, sign_enable>::operator-=(const block_t val)
{
    blocks[0] -= val;

    // check if underflow happened
    if (blocks[0] > (blocks[0] + val)) blocks[1]--;
}

FULL_TEMPLATE
void bigint<num_blocks, block_t, sign_enable>::operator-=(const bigint<num_blocks, block_t, sign_enable> val)
{
    for (int i = 0 ; i < num_blocks - 1 ; i++)
    {
        blocks[i] -= val;

        if(blocks[i] > (blocks[0] + val)) blocks[i + 1]--;
    }
}

FULL_TEMPLATE 
void bigint<num_blocks, block_t, sign_enable>::operator*=(const block_t val)
{
    
}


#pragma region CONSTRUCTORS

FULL_TEMPLATE
bigint<num_blocks, block_t, sign_enable>::bigint(const block_t val)
{
    blocks = {val};
}






#pragma endregion