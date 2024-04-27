// LC268 - Missing number
//O(n) memory complexity solution is easy
// The trick to get O(1) solution is to use
// XOR. You XOR the input array with the ideal
// array where all elements are present. The
// missing number is left out and that's the
// answer. Another way is to find the sum
// from 0 to n, the current sum of the array.
// The difference is the missing number.
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size(); // not a part of loop
        int n = nums.size();
        for(int i = 0; i<n; i++)
        {
            // xoring
            ans ^= nums[i] ^ i;
        }
        return ans;
    }
};
