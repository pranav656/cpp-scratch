class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        // push the gates into the queue
        for(int i = 0 ; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        // start search from the gates
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i<4; i++)
            {
                int x = r + dirs[i][0];
                int y = c + dirs[i][1];
                // the last condition also acts as a visited node check
                if(x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] != INT_MAX) {
                    continue;
                }
                grid[x][y]=grid[r][c]+1;
                q.push({x, y});

            }
        }
    }
};
