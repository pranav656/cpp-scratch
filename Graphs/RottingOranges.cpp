// LC994 - Rotting Oranges
class Solution {
public:
    int rows, cols, gridsize;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, 
                                {0, -1}, {0, 1}};
    int orangesRotting(vector<vector<int>>& grid) {
        rows = grid.size(); cols = grid[0].size();
        gridsize = rows*cols;
        // Queue for BFS
        queue<pair<int, int>> q;
        int number_of_fresh_oranges = 0, empty_cells = 0,
        number_of_rotten_oranges = 0;
        for(int i = 0; i< rows; i++) {
            for(int j = 0; j<cols; j++) {
                if(grid[i][j] == 2) {
                    // push rotten oranges to processed
                    // in the queue
                    q.push({i, j});
                    number_of_rotten_oranges++;
                }
                else if (grid[i][j] == 1) {
                    number_of_fresh_oranges++;
                }
                else {
                    empty_cells++;
                }
            }
        }
        // base cases where we start with empty cells
        // or complete fresh/rotten oranges
        if(empty_cells == gridsize) return 0;
        if (number_of_rotten_oranges == gridsize) return 0;
        if (number_of_fresh_oranges == gridsize) return -1;

        // start with -1 since 
        // the queue starts at existing stage
        int time = -1;
        while(!q.empty()) {
            // process current state first
            int size = q.size();
            time++;
            while(size--)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i = 0; i<dirs.size(); i++)
                {
                    int x = r+dirs[i][0];
                    int y = c+dirs[i][1];
                    if (x < 0 || x >=rows || y < 0 || y >= cols) continue;
                    // if orange present, contaminate
                    if(grid[x][y] == 1)
                    {
                        grid[x][y] = 2;
                        number_of_fresh_oranges--;
                        q.push({x, y});
                    }
                }
            }
        }
        if (number_of_fresh_oranges == 0) return time;
        return -1;
    }
};
