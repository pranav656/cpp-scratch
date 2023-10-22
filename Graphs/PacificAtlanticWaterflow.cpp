// LC417 (also Blind75) - Pacific Atlanatic Water Flow
// Brute Force solution:
// DFS on every point in the grid (O(m*n)^2)
// Optimized solution:
// Start from corner nodes and check which nodes are
// reachable from those nodes but with the inverse 
// height condition.Time and space complexity of this approach
// is O(m*n).
class Solution {
public:
    int rows, cols;
    vector<vector<bool>> pacific, atlantic;
    void dfs(int r, int c, vector<vector<bool>>& reachable, int prevHeight, 
            vector<vector<int>>& heights)
    {
        if(r < 0 || c < 0 || r == rows || c == cols) return;
        if (reachable[r][c] || heights[r][c] < prevHeight) return;
        reachable[r][c] = true;
        dfs(r+1, c, reachable, heights[r][c], heights);
        dfs(r-1, c, reachable, heights[r][c], heights);
        dfs(r, c+1, reachable, heights[r][c], heights);
        dfs(r, c-1, reachable, heights[r][c], heights);

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        vector<vector<int>> res;
        rows = heights.size(); cols = heights[0].size();
        pacific = vector<vector<bool>>(rows, vector<bool>(cols, false));
        atlantic = vector<vector<bool>>(rows, vector<bool>(cols, false));
        // First go through top and bottom rows
        for(int c = 0; c<cols; c++)
        {
            // first row pacific ocean
            dfs(0, c, pacific, heights[0][c], heights);
            // last row atlantic
            dfs(rows-1, c, atlantic, heights[rows-1][c], heights);
        }
        // Next go through the left and the right cols
        for(int r = 0; r<rows; r++)
        {
            // first cols pacific ocean
            dfs(r, 0, pacific, heights[r][0], heights);
            // last col atlantic ocean
            dfs(r, cols-1, atlantic, heights[r][cols-1], heights);
        }
        // build the final result 
        for(int r = 0; r<rows; r++)
        {
            for(int c = 0; c<cols; c++)
            {
                if(pacific[r][c] && atlantic[r][c])
                {
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }
};
