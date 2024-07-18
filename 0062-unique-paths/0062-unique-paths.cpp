class Solution {
public:
//     int uniquePaths(int m, int n) {
        
//     }
    int solve(int i, int j, int &n, int &m, vector<vector<int>>&dp)
    {
        if (i < 0 or j < 0 or i >= n or j >= m)
            return 0;
        
        if (i == n - 1 and j == m - 1)
            return 1;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int down = solve(i + 1, j, n, m, dp);
        int right = solve(i, j + 1, n, m, dp);
        
        return dp[i][j] = down + right;
    }
    
    int uniquePaths(int n, int m) {
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solve(0, 0, n, m, dp);
    }
};