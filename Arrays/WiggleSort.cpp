// LC280 - Wiggle Sort
// Sorting Based Approach:
// Sort and then swap i and i+1 th element
// as you iterate through the array
// O(n) approach:
// Key idea to realize is that odd
// indices need to be greater than the previous
// element and even indices need to be less
// than the previous element.
// Iterate through the array and check if the
// condition is not met, if yes, swap i and i-1th element.
// Practical applications:
// Financial Data Visualization - Visualize highs and lows of prices
// Load Balancing - Alternating between high and low loads
// Inventory Managment - Alternate between highs and lows
// Pattern Design - Alternative between high and low shades
// Game design - Alternate between easy and difficult problems 
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i<n; i++)
        {
            if( ((i&1)&& nums[i] < nums[i-1]) || 
            (!(i&1) && nums[i] > nums[i-1]))
            {
                swap(nums[i], nums[i-1]);
            }
        }
    }
};
