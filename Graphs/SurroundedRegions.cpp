// LC130 - Surrounded regions
// Key idea:
// The key idea is to recognize
// that if a chain of 0 is connected
// to a boundary, then it cannot be 
// converted to 'X'. DFS from the corners
// where there are 0 and mark those cells wherever
// you see '0's. Time complexity is O(rows*cols).
class Solution {
public:
    int rows, cols;
    void dfs(vector<vector<char>>& board, int i, int j)
    {
        if(i<0 || j<0 || i>=rows || j >= cols || board[i][j] != 'O') return;
        board[i][j] = 'T';
        dfs(board, i-1, j);
        dfs(board, i+1, j);
        dfs(board, i, j-1);
        dfs(board, i, j+1);
    }
    void solve(vector<vector<char>>& board) {
        rows = board.size(); cols = board[0].size();

        for(int i = 0; i< rows; i++) {
            if(board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if(board[i][cols-1] == 'O') {
                dfs(board, i, cols-1);
            }
        }

        for(int j = 0; j<cols; j++) {
            if(board[0][j] == 'O') {
                dfs(board, 0, j);
            }
            if(board[rows-1][j] == 'O') {
                dfs(board, rows-1, j);
            }
        }

        for(int i = 0; i<rows; i++)
        {
            for(int j = 0; j<cols; j++)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
    }
};
