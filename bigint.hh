#ifndef __BIGINT_HH__
#define __BIGINT_HH__




template <int num_blocks, typename blocktype, bool sign_enable>
class bigint
{
    protected:
        blocktype blocks[num_blocks];

    public:
        void operator+=(const int val);
        void operator+=(const blocktype val);
        void operator+=(const bigint<num_blocks, blocktype, sign_enable> val);

        void operator-=(const int val);
        void operator-=(const blocktype val);
        void operator-=(const bigint<num_blocks, blocktype, sign_enable> val);

        void operator*=(const int val);
        void operator*=(const blocktype val);
        void operator*=(const bigint<num_blocks, blocktype, sign_enable> val);

        void operator/=(const int val);
        void operator/=(const blocktype val);
        void operator/=(const bigint<num_blocks, blocktype, sign_enable> val);

        void operator<<=(const int shift);
        void operator>>=(const int shift);

        void operator&=(const int val);
        void operator&=(const blocktype val);
        void operator&=(const bigint<num_blocks, blocktype, sign_enable> val);

        void operator|=(const int val);
        void operator|=(const blocktype val);
        void operator|=(const bigint<num_blocks, blocktype, sign_enable> val);

        void operator^=(const int val);
        void operator^=(const blocktype val);
        void operator^=(const bigint<num_blocks, blocktype, sign_enable> val);


        const bigint<num_blocks, blocktype, sign_enable> operator+(const int val);
        const bigint<num_blocks, blocktype, sign_enable> operator+(const blocktype val);
        const bigint<num_blocks, blocktype, sign_enable> operator+(const bigint<num_blocks, blocktype, sign_enable> val);

        const bigint<num_blocks, blocktype, sign_enable> operator-(const int val);
        const bigint<num_blocks, blocktype, sign_enable> operator-(const blocktype val);
        const bigint<num_blocks, blocktype, sign_enable> operator-(const bigint<num_blocks, blocktype, sign_enable> val);

        bigint(const int val);
        bigint(const blocktype val);
        bigint(const blocktype val...);
};



#endif