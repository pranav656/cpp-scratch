// LC198 - House Robber
// DP approach:
// subproblem:
// the maximum possible value
// that can be obtained by robbing house
// at a given position. You need to
// look only upto previous two positions
// you can choose the maximum of two positions
// either rob the previous position or the one before
// that. take the maximum of those. Time
// complexity O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 =0, rob2=0;
        // rob1 rob2, n1, n2,....
        for(int n : nums)
        {
            // key idea: either you can choose
            // to rob the cell before the current 
            // cell (represented by rob2) or 
            // choose to rob the current cell (n)
            // + 2 cells before (rob1). Store in
            // temporary result variable. This temporary
            // result will be adjacent cell(rob2) and the current rob2
            // will be rob1 for the next element
            int tmp = max(n+rob1, rob2);
            rob1 = rob2;
            rob2 = tmp;
        }
        // Return rob2 since that will contain the maximum value for
        // all the cells contained in the array.
        return rob2;
    }
};
