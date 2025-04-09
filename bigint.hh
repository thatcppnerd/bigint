#ifndef __BIGINT_HH__
#define __BIGINT_HH__

/// @brief An arbitrary-length integer
/// @tparam __block_t The type of the blocks that make up the integer. Only operable integer types accepted.
/// @tparam __num_blocks The number of blocks that make up the integer.
/// @tparam __sign_enable Toggles signed or unsigned operations.
template <int __num_blocks, typename __block_t, bool __sign_enable> class bigint;

template <int __num_blocks, typename __block_t, bool __sign_enable>
struct __bigint_common
{
    __block_t blocks[__num_blocks];

    const int&& num_blocks = __num_blocks;
    using block_t = __block_t;
    const bool&& sign_enable = __sign_enable;

    void operator+=(const __block_t val);
    void operator+=(const bigint<__num_blocks, __block_t, __sign_enable> val);

    void operator-=(const __block_t val);
    void operator-=(const bigint<__num_blocks, __block_t, __sign_enable> val);

    virtual void operator*=(const __block_t val);
    virtual void operator*=(const bigint<__num_blocks, __block_t, __sign_enable> val);

    virtual void operator/=(const __block_t val);
    virtual void operator/=(const bigint<__num_blocks, __block_t, __sign_enable> val);

    void operator<<=(const int shift);
    void operator>>=(const int shift);

    void operator&=(const __block_t val);
    void operator&=(const bigint<__num_blocks, __block_t, __sign_enable> val);

    void operator|=(const __block_t val);
    void operator|=(const bigint<__num_blocks, __block_t, __sign_enable> val);

    void operator^=(const __block_t val);
    void operator^=(const bigint<__num_blocks, __block_t, __sign_enable> val);


    const bigint<__num_blocks, __block_t, __sign_enable> operator+(const __block_t val);
    const bigint<__num_blocks, __block_t, __sign_enable> operator+(const bigint<__num_blocks, __block_t, __sign_enable> val);

    const bigint<__num_blocks, __block_t, __sign_enable> operator-(const __block_t val);
    const bigint<__num_blocks, __block_t, __sign_enable> operator-(const bigint<__num_blocks, __block_t, __sign_enable> val);

    __bigint_common(const __block_t val);
    __bigint_common(const int count, const __block_t val...);
};


template <int __num_blocks, typename __block_t, bool __sign_enable>
struct bigint : public __bigint_common<__num_blocks, __block_t, __sign_enable>
{
    bigint(const __block_t val);
    bigint(const int count, const __block_t val...);
};

#endif