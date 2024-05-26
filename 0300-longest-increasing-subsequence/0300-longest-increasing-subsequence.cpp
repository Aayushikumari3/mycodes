class Solution {
public:
    int leng(vector<int>& nums, int n, int index, int prev,vector<vector<int>>& dp) {
        if (index == n) {
            return 0;
        }
       if(dp[index][prev+1]!=-1)
           return dp[index][prev+1];
        int taken = 0;
        if (prev == -1 || nums[index] > nums[prev]) {
            taken = 1 + leng(nums, n, index + 1, index,dp);
        }
        int not_taken = leng(nums, n, index + 1, prev,dp);

        dp[index][prev+1]=max(taken, not_taken);
        return dp[index][prev+1];
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>> dp(n+1,-1);
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return leng(nums, nums.size(), 0, -1,dp);
    }
};
