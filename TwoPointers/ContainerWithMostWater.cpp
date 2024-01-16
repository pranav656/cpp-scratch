// LC11 - Container with most water
// Brute force solution - O(n^2) time complexity, get all possible
// pairs of lengths.
// O(1) time complexity solution - Take the left and right
// pointers to be at the end of each array, move the one 
// which has the lesser height (to improve search for the max area),
// keep track of the max area and return it once the left and
// right pointers intersect each other
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r= height.size() -1;
        int maxArea = 0;
        while(l < r)
        {
            int currentArea = (r-l)*min(height[l], height[r]);
            maxArea = max(maxArea, currentArea);
            if(height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }

        return maxArea;
    }
};
