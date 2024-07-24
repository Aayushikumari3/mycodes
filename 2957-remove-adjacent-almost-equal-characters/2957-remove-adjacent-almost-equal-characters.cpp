class Solution {
public:
    int removeAlmostEqualCharacters(string word) 
    {
        int ans =0;
        for(int i=1;i<word.size()-1;i++)
        {
            if(abs(word[i]-word[i-1])<=1 and abs(word[i]-word[i+1])<=1)
            {
                word[i]='#';
                ans++;
            }
        }
        for(int i=1;i<word.size();i++)
        {
            if(abs(word[i]-word[i-1])<=1)
            {
                word[i]='#';
                    ans++;
            }
        }
        return ans;
    }
};