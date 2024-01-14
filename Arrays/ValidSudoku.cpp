// LC36 - Valid Sudoku

class Solution {
public:
    // 0 to 9
    set<int> visited_rows;
    set<int> visited_cols;
    vector<unordered_set<char>> visited_grid;
    
    bool isValidRow(vector<vector<char>>& board, int r)
    {
        set<char> seen;
        if(visited_rows.find(r) != visited_rows.end()) return true;
        for(int j = 0; j<board[0].size(); j++)
        {
            if(board[r][j] != '.' && seen.find(board[r][j])!= seen.end()) return false;
            seen.insert(board[r][j]);
        }
        visited_rows.insert(r);
        return true;
    }

    bool isValidCol(vector<vector<char>>& board, int c)
    {
        set<char> seen;
        if(visited_cols.find(c) != visited_cols.end()) return true;
        for(int i = 0; i<board[0].size(); i++)
        {
            if(board[i][c] != '.' && seen.find(board[i][c])!= seen.end()) return false;
            seen.insert(board[i][c]);
        }
        visited_cols.insert(c);
        return true;
    }

    bool isValidGrid(vector<vector<char>>& board, int r, int c)
    {
        int grid_id = r/3 * 3 + c/3;
        if(board[r][c] != '.' && visited_grid[grid_id].find(board[r][c]) != visited_grid[grid_id].end()) return false;
        visited_grid[grid_id].insert(board[r][c]);
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        visited_grid = vector<unordered_set<char>>(9, unordered_set<char>{});
        for(int i = 0; i<board.size(); i++)
        {
            for(int j = 0; j< board[0].size(); j++)
            {
                if(!isValidRow(board, i) || !isValidCol(board, j) || !isValidGrid(board, i, j)) return false;
            }
        }

        return true;
    }
};
