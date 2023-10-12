// LC1658 - minimum operations to reduce x to zero

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // The key idea is to rephrase this problem
        // to find a subarray where the target is 
        // sum of input array - targe. We need to
        // maximize the length of this array so as
        // to minimize the number of operations.
        int sum = accumulate(nums.begin(), nums.end(), 0);
        cout<<sum<<endl;
        int target = sum - x;
        // note: this logic works since only positive
        // numbers are present in the array
        if(target == 0) return nums.size();
        int max_window = 0, l = 0, curr_sum = 0;
        for(int r = 0; r<nums.size(); r++) {
            // start the right pointer from the left
            // and increase the window until sum becomes greater than
            // or equal to target
            curr_sum += nums[r];
            // This loop below is executed only when sum exceeds target
            // you move the left ptr until current sum < target or
            // if left pointer exceeds right pointer
            while( l <= r && curr_sum > target)
            {
                // remove left element and decrease current
                // sum from the window
                curr_sum -= nums[l];
                l++;
            }
            if(curr_sum == target)
            {
                // update max window if target is found
                // i.e. there could be multiple windows
                max_window = max(max_window, r - l + 1);
            }
        }
        // if max_len remains zero, solution not found, return -1
        if(max_window == 0) return -1;
        return nums.size() - max_window;
    }
};
