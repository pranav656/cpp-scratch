// Leetcode 200 - Number of islands
//  idea: Number of connected 
// graphs. Recursively visit
// every island and its
// neighbours(dfs). We need to find which islands
// form a group, so we can use a prev variable 
// that just keeps track of the value of the 
// previously visited node. Time complexity
// is O(m*n), where m is the number of rows and columns.

class Solution {
  public: vector < vector < int >> visited;
  int rows,
  cols;
  int island_number = 0;
  // DFS will return the island number
  void dfs(vector < vector < char >> & grid, int i, int j, char prev) {
    if (i >= rows || i < 0 || j < 0 ||
      j >= cols) {
      return;
    }
    if (visited[i][j] || grid[i][j] == '0') {
      return;
    }
    visited[i][j] = 1;
    dfs(grid, i + 1, j, grid[i][j]);
    dfs(grid, i - 1, j, grid[i][j]);
    dfs(grid, i, j - 1, grid[i][j]);
    dfs(grid, i, j + 1, grid[i][j]);
    if (grid[i][j] == '1' && prev == '0') {
      island_number++;
    }
  }
  int numIslands(vector < vector < char >> & grid) {
    rows = grid.size();
    cols = grid[0].size();
    visited = vector < vector < int >> (rows, vector < int > (cols, 0));
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        dfs(grid, i, j, '0');
      }
    }
    return island_number;
  }
};
