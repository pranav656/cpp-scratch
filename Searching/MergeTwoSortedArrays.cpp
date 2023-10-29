// LC88 - Merge Sorted Arrays
// One approach is to merge the arrays and sort them. 
// Time complexity is O(m+nlog(m+n)). 
// Optimized approach is to iterate element by element
// and do a 
// comparison and insert into the righ
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(m);
        // store nums1 in a temporary array
        for(int i = 0; i<m; i++)
        {
            temp[i] = nums1[i];
        }
        int i = 0, j = 0, k = 0;
        while(i < m && j < n) {
            if(temp[i] > nums2[j]) {
                nums1[k] = nums2[j];
                j++; k++;
            }
            else {
                nums1[k] = temp[i];
                i++;k++;
            }
        }

        // Cases for remaining elements when 
        // one vector is larger than the other
        while(i < m) {
            nums1[k] = temp[i];
            i++; k++;
        }

        while(j < n) {
            nums1[k] = nums2[j];
            j++;k++;
        }
    }
};
