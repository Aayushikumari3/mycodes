class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int product = 1; 
        int i = 0;
        
        for (int j = 0; j < nums.size(); j++) {
            product *= nums[j]; 
            
            while (i <= j && product >= k) {
                product /= nums[i++]; 
            }
    
            ans += (j - i + 1);
        }
        
        return ans;
    }
};
