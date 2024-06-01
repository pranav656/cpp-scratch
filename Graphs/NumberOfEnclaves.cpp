// LC1020 - Number of enclaves
// Company: Amazon
// Start search from the corner
// and mark the nodes which are visited.
// The nodes which are unvisited, but 
// are land nodes need to be included in the answer
// Time and Memory complexity : O(n)
class Solution {
private:
    void dfs(int m, int n, int i, int j, vector<vector<int>>& visited, 
    vector<vector<int>>& grid) {
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        visited[i][j] = 1;

        for(int k = 0; k < 4; k++)
        {
            int nr = i+dr[k];
            int nc = j+dc[k];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n &&
                !visited[nr][nc] && grid[nr][nc]==1) {
                    dfs(m, n, nr, nc, visited, grid);
                }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n= grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int i = 0; i<n; i++)
        {
            if(grid[0][i]==1) {
                dfs(m, n, 0, i, visited, grid);
            }
            if(grid[m-1][i]==1) {
                dfs(m, n, m-1, i, visited, grid);
            }
        }

        for(int i= 0; i<m; i++)
        {
            if(grid[i][0] && !visited[i][0])
            {
                dfs(m, n, i, 0,visited, grid);
            }
            if(grid[i][n-1] && !visited[i][n-1]) {
                dfs(m, n, i, n-1, visited, grid);
            }
        }

        int ans = 0;
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j]==1 && !visited[i][j]) ans++;
            }
        }
        return ans;
    }
};
