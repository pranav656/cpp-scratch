// Leetcode239 (Hard) - Sliding Window Maximun
// The number of sliding windows
// that can be obtained is n -k. By using the
// brute force approach, finding max
// on each iteration, the time complexity would be
// O(k* (n-k)). The key idea behind obtaining a O(n)
// approach is realizing to use a deque for storing
// the indices of the max element seen so far. If the
// index goes out of range of the current window, it
// would need to be removed from the deque. 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d;
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            // Following conditions are being checked:
            // d.size() > k --> the deque need not
            // be greater than size k, the max window
            // size is k.
            // (!d.empty() && d.front() <= i - k) --> checks for empty queue and his 
            // condition ensures that only elements in the current window
            // are considered for the answer
            while(d.size() > k || (!d.empty() && d.front() <= i - k)) {
                d.pop_front();
            }
            // The below condition preserves that the deque
            // is always monotonically decreasing, in that
            // way only the maximum elements are kept track of
            while(!d.empty() && nums[d.back()] < nums[i])
            {
                d.pop_back();
            }
            // push indices into the deque
            // as they are visited. They are removed
            // later as needed. 
            d.push_back(i);

            // when the first window is reached, start
            // adding results to the queue
            if ( i >= k - 1) res.push_back(nums[d.front()]);
        }
        return res;
    }
};
