#ifndef __BIGINT_HH__
#define __BIGINT_HH__


template <int num_blocks, typename block_t, bool sign_enable> class bigint;

template <int num_blocks, typename block_t, bool sign_enable>
class bigint
{
    protected:
        block_t blocks[num_blocks];

    public:
        void operator+=(const block_t val);
        void operator+=(const bigint<num_blocks, block_t, sign_enable> val);

        void operator-=(const block_t val);
        void operator-=(const bigint<num_blocks, block_t, sign_enable> val);

        void operator*=(const block_t val);
        void operator*=(const bigint<num_blocks, block_t, sign_enable> val);

        void operator/=(const block_t val);
        void operator/=(const bigint<num_blocks, block_t, sign_enable> val);

        void operator<<=(const int shift);
        void operator>>=(const int shift);

        void operator&=(const block_t val);
        void operator&=(const bigint<num_blocks, block_t, sign_enable> val);

        void operator|=(const block_t val);
        void operator|=(const bigint<num_blocks, block_t, sign_enable> val);

        void operator^=(const block_t val);
        void operator^=(const bigint<num_blocks, block_t, sign_enable> val);


        const bigint<num_blocks, block_t, sign_enable> operator+(const block_t val);
        const bigint<num_blocks, block_t, sign_enable> operator+(const bigint<num_blocks, block_t, sign_enable> val);

        const bigint<num_blocks, block_t, sign_enable> operator-(const block_t val);
        const bigint<num_blocks, block_t, sign_enable> operator-(const bigint<num_blocks, block_t, sign_enable> val);

        bigint(const block_t val);
};

template <int num_blocks, bool sign_enable>
class bigint<num_blocks, short>



#endif