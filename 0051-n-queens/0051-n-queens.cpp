class Solution {
public:
    void solve(vector<string>& board, int col, vector<int>& leftrow, vector<int>& leftdiag, vector<int>& rightdiag, vector<vector<string>>& ans, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (leftrow[row] == 0 && leftdiag[row + col] == 0 && rightdiag[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                leftrow[row] = 1;
                leftdiag[row + col] = 1;
                rightdiag[n - 1 + col - row] = 1;
                solve(board, col + 1, leftrow, leftdiag, rightdiag, ans, n);
                board[row][col] = '.';
                leftrow[row] = 0;
                leftdiag[row + col] = 0;
                rightdiag[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> leftrow(n, 0), leftdiag(2 * n - 1, 0), rightdiag(2 * n - 1, 0);
        solve(board, 0, leftrow, leftdiag, rightdiag, ans, n);
        return ans;
    }
};
