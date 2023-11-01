// LC74 - Search a 2D matrix
// The key idea is to realize that elements
// on the left are smaller than  the current element and
// the elements on the bottom are always greater. 
// If the target is less than the current element
// then it should be on the previous column. 
// Worst case time complexity is O(n) in the case 
// of single rows, average case is O(log(m*n))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(); int cols = matrix[0].size();
        int r = 0, c = cols -1;
        while(r < rows && c >=0)
        {
            // if target is greater, 
            // the result should be next row
            if(target>matrix[r][c])
            {
                r++;
            }
            else if(target<matrix[r][c])
            {
                // if target is lesser
                // then it should be in the previous column
                c--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
