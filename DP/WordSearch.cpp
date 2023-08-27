
/*
LC79:
This solution recursively searches for the word pattern.
In order to ensure that the same board element is not taken into account,
you can mark the visited node as * so that it's not taken into account twice.
No optimization (memoization) has been done as the inputs are relatively small.
*/
class Solution {

public:
    bool IsPatternContainedInSufficContainedStartingAtXY(
        vector<vector<char> >& board, int x, int y,
        const string& pattern, int offset)
    {
        if (size(pattern) == offset) {
            return true;
        }
        if (x < 0 || x >= size(board) || y < 0 || y >= size(board[x])
            || board[x][y] != pattern[offset]) {
            return false;
        }
        // A trick to ensure the visited blocks
        // are not taken into account again
        char c = board[x][y];
        board[x][y] = '*';
        bool ret = IsPatternContainedInSufficContainedStartingAtXY(board, x - 1, y, pattern, offset + 1) || IsPatternContainedInSufficContainedStartingAtXY(board, x + 1, y, pattern, offset + 1) || IsPatternContainedInSufficContainedStartingAtXY(board, x, y - 1, pattern, offset + 1) || IsPatternContainedInSufficContainedStartingAtXY(board, x, y + 1, pattern, offset + 1);
        board[x][y] = c;
        return ret;
    }
    bool exist(vector<vector<char> >& board, string word)
    {
        vector<vector<int> > visited(board.size(),
            vector<int>(board[0].size(), 0));
        for (int i = 0; i < size(board); i++) {
            for (int j = 0; j < size(board[0]); j++) {
                if (IsPatternContainedInSufficContainedStartingAtXY(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
