// class Solution {
// public:
//     bool mannubaby(string str,unordered_set <string> seti,vector<int> dp,int index)
//     {
//         int n=str.size();
//         if(index==n)
//             return 0;
            
//             if(dp[index]!=-1)
// return dp[index];
        
       
//                 for(int i=index;i<n;i++)
//         {
//             if()
//         }
//     }
    
    
//     bool wordBreak(string s, vector<string>& wordDict) {
       
        
//         vector<int> dp(s.size(),-1);
//         unordered_set<string> seti(wordDict.begin(), wordDict.end());
//         return mannubaby(s,seti,dp,0);
//     }
// };
class Solution {
private:
    bool wordBreak(string s, unordered_set<string> &set, vector<int> &memo, int start){
        if(start == s.size()){
            return true;
        }
        if(memo[start] != -1){
            return memo[start];
        }
        for(int i=start; i<s.size(); i++){
            if(set.count(s.substr(start, i+1-start)) && wordBreak(s, set, memo, i+1)){
                memo[start] = true;
                return true;
            }
        }
        return memo[start] =false;
        }   
            public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size(), -1);
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        return wordBreak(s, set, memo, 0);
    }
    };