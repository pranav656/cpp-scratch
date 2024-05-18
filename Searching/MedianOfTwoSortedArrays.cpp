// LC 4 - Median of two sorted arrays
// O(n) approach using merge sort. Go through
// both the array elements and merge them based
// on which element is smaller.
// TODO: O(log(m+n)) approach using binary search
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int i = 0, j = 0;
        vector<int> merged_array;
        while((i < m) && (j < n))
        {
            if(nums1[i] <= nums2[j])
            {
                merged_array.push_back(nums1[i]);
                i++;
            }
            else
            {
                merged_array.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m)
        {
            merged_array.push_back(nums1[i]);
            i++;
        }

        while(j < n)
        {
            merged_array.push_back(nums2[j]);
            j++;
        }
        int merged_size = m+n; 
        int mid = merged_size/2;
        if(merged_size % 2 == 0)
        {
            return (merged_array[mid-1] + merged_array[mid])/2.0;
        }
        else
        {
            return merged_array[mid];
        }
    }
};
