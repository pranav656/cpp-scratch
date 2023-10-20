// LC695 - Max Area of Island
// This problem is an extension of another Leetcode 
// problem 'Number of Islands'. Instead of counting the number of
// islands, we need to calculate the maximum area of an island.
// We will just keep track of the area of the islands as we
// visit them.
// The time and space complexity is same as the other problem, O(m*n)
class Solution {
public:
    int cols, rows;
    vector<vector<int>> visited;
    int island_number = 0;
    int max_area = 0;
    int curr_area =0;
    void dfs(int i, int j, int prev, vector<vector<int>>& grid)
    {
        if(i < 0 || i >=rows || j<0 || j >= cols)
        {
            return;
        }
        // don't merge with prev condition as it can
        // lead to undefined behavior in case of 
        // out of bounds access
        if(visited[i][j] || grid[i][j] == 0)
        {
            return;
        }
        visited[i][j] = 1;
        dfs(i+1, j, grid[i][j], grid);
        dfs(i-1, j, grid[i][j], grid);
        dfs(i, j+1, grid[i][j], grid);
        dfs(i, j-1, grid[i][j], grid);
        if(prev == 0 && grid[i][j] == 1)
        {
            curr_area = 1;
            max_area = max(max_area, curr_area);
        }
        else if (prev == 1 && grid[i][j])
        {
            if(curr_area ==0)
            {

                // This if condition is a quick hack
                // to cover for cases where there are
                // only '1's in the grid
                curr_area++;
            }
            curr_area++;
            max_area = max(max_area, curr_area);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size(); cols = grid[0].size();
        visited  = vector<vector<int>>(rows, vector<int>(cols, 0));
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                dfs(i, j, 0, grid);
            }
        }

        return max_area;
    }
};
