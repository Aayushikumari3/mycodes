class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      if(nums.size()==0)
          return 0;
        
        int longest=0,cnt=0;
        int curr=0,ele=0;
        unordered_set <int> myset;
        for(int i=0;i<nums.size();i++)
            myset.insert(nums[i]);
        for (auto it : myset) {
        if (myset.find(it - 1) == myset.end()) {
            int cnt = 1;
            int x = it;
            while (myset.find(x + 1) != myset.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
        return longest;
    }
};