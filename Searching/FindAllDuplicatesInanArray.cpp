// LC442 - Find all Duplicates
// The key insight to solve this problem
// is that the numbers are in the range 1 to n
// You can use this fact to see this array 
// as indices of the input elements. 
// You could use the input array and mark the visited 
// nodes as negative. Using this fact, you whenever
// you reach a negative node, you can add that to the result array.
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for(auto num : nums)
        {
            int x = abs(num);
            // minimum element starts at 1
            if(nums[x-1] < 0)
            {
                result.push_back(x); 
            }
            nums[x-1] *= -1;
        }
        return result;
    }
};
