// (TODO) Leetcode 200 - Number of islands
// Initial idea: Number of connected 
// graphs.

class Solution {
public:
    /*vector<vector<int>> visited;
    int rows, cols;
    int island_number = 0;
    // DFS will return the island number
    void dfs(vector<string>& grid, int i, int j, char prev)
    {
        if(i >= rows || i < 0 || j < 0 
           || j >= cols || visited[i][j]) return;
        dfs(grid, i+1, j, grid[i][j]);
        dfs(grid, i, j+1, grid[i][j]);
        dfs(grid, i, j-1, grid[i][j]);
        dfs(grid, i, j+1, grid[i][j]);
        if(grid[i][j]=='1' && prev == '0') island_number++;
        visited[i][j] = 1;
    }*/
    int numIslands(vector<string>& grid) {
        int island_number = 0;
        /*for(string s: grid)
        {
            cout<<s<<endl;
        }
        rows = grid.size(); cols = grid[0].size();
        visited = vector<vector<int>>(rows, vector<int>(cols ,0));
        for(int i = 0; i<rows; i++)
        {
            for(int j = 0; j<cols; j++)
            {
                dfs(grid, i, j, '0');
            }
        }*/
        return island_number;
    }
};
