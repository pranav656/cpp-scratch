// LC66 - Jump Game
// Brute force solution:
// Make an array of booleans and fill it with
// reachable positions at indices. May not be sufficient for
// large datasets. Time complexity O(n^2)
// Greedy approach:
// Keep track of the max reachable position at each index
// If we ever reach position which is greater than max reachable
// position, then return false, else return true.
// Time Complexity (O(n)), Space complexity O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reachable = 0;
        for(int i = 0; i<nums.size();i++)
        {
            if(i > max_reachable) return false;
            max_reachable = max(max_reachable, i+nums[i]);
        }
        return true;
    }
};
