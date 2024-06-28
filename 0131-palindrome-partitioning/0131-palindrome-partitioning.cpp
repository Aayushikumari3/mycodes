class Solution {
public:
    
    
    bool isPallindrome(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--])
            
                return false;
            }
            return true;
                
    }
    
    void solve(string s,vector<string> &path,vector<vector<string>> &result,int index)
    {
        if(index==s.size())
        {
            result.push_back(path);
            return;       
        }
        for(int i=index;i<s.size();i++)
        {
            if(isPallindrome(s,index,i))
            {
               path.push_back(s.substr(index,i-index+1)); 
                solve(s,path,result,i+1);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
         vector<vector<string>> result;
        vector<string> path;
        solve(s,path,result,0);
        return result;
    }
};