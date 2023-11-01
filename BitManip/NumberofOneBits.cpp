class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c = 0;
        for(int i = 0; i<=31; i++)
        {
            if(n>>i&1) c++;
        }
        return c;
    }
};
