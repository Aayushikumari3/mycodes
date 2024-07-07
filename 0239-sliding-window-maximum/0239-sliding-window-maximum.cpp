class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
      
        int l=0,r=0;        //  l=left pointer, r=right pointer
        
        priority_queue<pair<int,int>> pq;       
        
        if(k>nums.size()) return ans;
        
        while(r<nums.size()){
            if(r-l+1<k){
                pq.push(make_pair(nums[r],r));
                r++;
            }
            else{
                if(r<nums.size()) pq.push(make_pair(nums[r],r));
                
                if(l<=pq.top().second)
                    ans.push_back(pq.top().first);
                else{
                    while(l>pq.top().second){
                        pq.pop();
                    }
                    ans.push_back(pq.top().first);
                }
                
                l++;
                r++;
                
            }
        }
        return ans;
    }
};