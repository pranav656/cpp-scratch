// LC162 - Find Peak element
// This would have been a easy problem,
// if it could be done in O(n) but it needs to
// be done in O(log n) time. It needs to 
// be solved with a modified binary search. The key 
// idea here is to look for the side of the 
// array where you know there's a guarantee of finding 
// a peak, i.e. search for the direction where the element
// is increasing.
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0; int r = nums.size() - 1;
        int m = 0;
        while(l <= r)
        {
            m = l + (r-l)/2;
            // peak is on the left side
            if ( (m > 0) && (nums[m] < nums[m-1]))
            {
                r = m - 1;
            }
            // peak on the right hand side
            else if ((m < nums.size()-1) &&  nums[m+1] > nums[m])
            {
                l = m+1;
            }
            else
            {
                return m;
            }
        }
        // won't reach here
        // but to satisfy compiler
        return m;
    }
};
