class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sumi = 0, mini = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
          sumi += nums[i];
               // sumi = max(sumi, mini);
            if(sumi>mini)
                mini=sumi;
        
            if (sumi < 0)
                sumi = 0;
            
        }
        return mini;
    }
};

