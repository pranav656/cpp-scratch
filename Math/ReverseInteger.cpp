// LC7 - Reverse Integer
// Amazon
// Constraints - Don't use more than 32 bits
class Solution {
public:
    int reverse(int x) {
        int r = 0;
        while(x)
        {
            // since the next multiplication would
            // take this out of range of int
            if(r > INT_MAX/10 || r < INT_MIN/10) return 0;
            r = r*10 + x%10;
            x = x/10;
        }
        if(r > INT_MAX || r < INT_MIN) return 0;
        return r;
    }
};
