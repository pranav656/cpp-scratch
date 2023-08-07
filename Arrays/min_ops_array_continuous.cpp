// LC2009: Minimum Number of Operations to Make Array Continuous
// The straight forward approach is to sort and search for the next continuous 
// element for the next continuous element in every possible start point and if
// not found update the count, however this leads to
// excess time as the time complexity is O(n^2*logn), see solution below:
//class Solution {
/*public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int min_count = numeric_limits<int>::max();
        for(int i = 0; i<nums.size(); i++)
        {
            int count = 0;
            for(int j = nums[i]; j <= nums[i] + nums.size()-1; j++)
            {
                auto found = binary_search(nums.begin(), nums.end(), j);
                if(!found)
                {
                    count++;
                }
            }
            min_count = min(count, min_count);
        }

        return min_count;
    }
};*/

// The more optimized solution uses a sliding window approach
// First sort the array, and search for the end element in case
// the array was continuous. If the index is found then
// you would need to replace elements excluding the range
// in which the element to the upper bound was not found. 
// You optimize the search by using the max possible element in 
// a continuous array for each starting point. The time complexity would be
// O(nlogn) due to the optimized search
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        auto last = unique(nums.begin(), nums.end());
        nums.erase(last, nums.end());

        int min_ops = numeric_limits<int>::max();
        for(int i = 0; i<nums.size(); i++)
        {
            int idx = upper_bound(nums.begin(), nums.end(), nums[i]+n-1) - nums.begin();
            min_ops = min(min_ops, n-(idx-i));
        }
        return min_ops;
    }
};
