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
// class Solution {
// private:
//     bool wordBreak(string s, unordered_set<string> &set, vector<int> &memo, int start){
//         if(start == s.size()){
//             return true;
//         }
//         if(memo[start] != -1){
//             return memo[start];
//         }
//         for(int i=start; i<s.size(); i++){
//             if(set.count(s.substr(start, i+1-start)) && wordBreak(s, set, memo, i+1)){
//                 memo[start] = true;
//                 return true;
//             }
//         }
//         return memo[start] =false;
//         }   
//             public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         vector<int> memo(s.size(), -1);
//         unordered_set<string> set(wordDict.begin(), wordDict.end());
//         return wordBreak(s, set, memo, 0);
//     }
    // };
class Solution {
public:
     unordered_map<string,bool>dp;
    bool solve(string s,unordered_set<string>&m){
        if(s.length()==0){
            return true;
        }
        if(dp.find(s)!=dp.end())
        return dp[s];
        for(int i=0;i<s.length();i++){
            string r=s.substr(0,i+1);
            if(m.count(r)){
                if(solve(s.substr(i+1),m))
                return dp[s]=true;
            }
        }
        return dp[s]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
         unordered_set<string>m;
        for(auto x:wordDict){
            m.insert(x);
        }
         return solve(s,m);
    }
};