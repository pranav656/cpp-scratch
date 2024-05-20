// LC1979 - Find greatest common divisor of an array
// Find min, max element and find gcd
class Solution {
public:
    int gcd (int a, int b)
    {
        if(a > b) return gcd(a-b, b);
        else if (a < b) return gcd(b-a, a);
        else return a; // equal case
    }
    int findGCD(vector<int>& nums) {
        int min_no = *min_element(nums.begin(), nums.end());
        int max_no = *max_element(nums.begin(), nums.end());
        return gcd(max_no, min_no);
    }
};
