// class Solution {
// public:
//     int mincoin(vector<int> &coins,int amount,vector<vector<int>> dp,int index)
//     {
//         int n=coins.size();
//         if(amount<0)
//             return INT_MAX;
//         if(index==n && amount!=0)
//         return INT_MAX;
//         if(amount==0)
//             return 0;//abdul
//         if(dp[index][amount]!=-1)
//             return dp[index][amount];
        
//         int exclude=mincoin(coins,amount,dp,index+1);
//         int include=0;
//         if(coins[index]<=amount)
//             include=mincoin(coins,amount-coins[index],dp,index)+1;
//         return dp[index][amount]=min(exclude,include);
        
        
//     }
//     int coinChange(vector<int>& coins, int amount) { 
//         int n=coins.size();
//         vector<vector<int>> dp(n+1,vector<int> (amount+1,-1));
//         sort(coins.begin(),coins.end(),greater<int>());
//         return mincoin(coins,amount,dp,0);
        
//     }
// };
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int mincoin(vector<int> &coins, int amount, vector<vector<int>> &dp, int index) {
        int n = coins.size();
        if (amount < 0)
            return INT_MAX; // Impossible scenario
        if (index == n && amount != 0)
            return INT_MAX; // Impossible scenario if coins are exhausted and amount is not zero
        if (amount == 0)
            return 0; // No coins needed for zero amount

        if (dp[index][amount] != -1)
            return dp[index][amount]; // Return memoized result
        
          int include = INT_MAX;
        if (coins[index] <= amount) {
            int res = mincoin(coins, amount - coins[index], dp, index);
            if (res != INT_MAX) {
                include = res + 1;
            }
        }
        int exclude = mincoin(coins, amount, dp, index + 1);
      
        return dp[index][amount] = min(exclude, include);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        sort(coins.begin(), coins.end(), greater<int>());
        int result = mincoin(coins, amount, dp, 0);
        return result == INT_MAX ? -1 : result;
    }
};

