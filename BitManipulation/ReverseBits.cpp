class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t n_r;
        for(int i = 0; i<32; i++)
        {
            n_r <<= 1;
            n_r |= n & 1;
            n >>= 1;
        }
        return n_r;
    }
};
