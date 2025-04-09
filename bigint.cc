#include "bigint.hh"

#define FULL_TEMPLATE template <int __num_blocks, typename __block_t, bool __sign_enable>
#define TEMPLATE_NO_BT template <int __num_blocks, bool __sign_enable>


FULL_TEMPLATE 
void __bigint_common<__num_blocks, __block_t, __sign_enable>::operator+=(const __block_t val)
{
    blocks[0] += val;

    // check if overflow happened
    if (blocks[0] < (blocks[0] - val)) blocks[1]++;
}

FULL_TEMPLATE
void __bigint_common<__num_blocks, __block_t, __sign_enable>::operator+=(const bigint<__num_blocks, __block_t, __sign_enable> val)
{
    for (int i = 0 ; i < __num_blocks - 1 ; i++)
    {
        blocks[i] += val;

        // check if overflow happened
        if(blocks[i] < (blocks[0] - val)) blocks[i + 1]++;
    }
}

FULL_TEMPLATE 
void __bigint_common<__num_blocks, __block_t, __sign_enable>::operator-=(const __block_t val)
{
    blocks[0] -= val;

    // check if underflow happened
    if (blocks[0] > (blocks[0] + val)) blocks[1]--;
}

FULL_TEMPLATE
void __bigint_common<__num_blocks, __block_t, __sign_enable>::operator-=(const bigint<__num_blocks, __block_t, __sign_enable> val)
{
    for (int i = 0 ; i < __num_blocks - 1 ; i++)
    {
        blocks[i] -= val;
        
        // check if overflow happened
        if(blocks[i] > (blocks[0] + val)) blocks[i + 1]--;
    }
}

FULL_TEMPLATE
void __bigint_common<__num_blocks, __block_t, __sign_enable>::operator*=(const __block_t val)
{    
    // multiply 
    for (int i = 0 ; i < __num_blocks ; i++)
    {
        blocks[i] *= val;
    }

    __block_t mid[__num_blocks - 1] = {};

    __block_t &&high_mask = (__block_t(0) - 1) << ((sizeof(__block_t) * 8)/2);


    for (int i = 0 ; i < __num_blocks - 1 ; i++)
    {
        mid[i] = blocks[i] + blocks[i + 1];
    }
}

FULL_TEMPLATE
void __bigint_common<__num_blocks, __block_t, __sign_enable>::operator/=(const __block_t val)
{

}

#pragma region CONSTRUCTORS

FULL_TEMPLATE
__bigint_common<__num_blocks, __block_t, __sign_enable>::__bigint_common(const __block_t val)
{
    blocks = {val};
}

FULL_TEMPLATE
__bigint_common<__num_blocks, __block_t, __sign_enable>::__bigint_common(const int count, const __block_t val...)
{
    blocks = {};

    for (int i = 0 ; i < count ; i++)
    {
        blocks[i] = val[i];
    }
}

FULL_TEMPLATE
bigint<__num_blocks, __block_t, __sign_enable>::bigint(const __block_t val) : __bigint_common<__num_blocks, __block_t, __sign_enable>(val)
{}

FULL_TEMPLATE
bigint<__num_blocks, __block_t, __sign_enable>::bigint(const int count, const __block_t val...) : __bigint_common<__num_blocks, __block_t, __sign_enable>(count, val)
{}


#pragma endregion