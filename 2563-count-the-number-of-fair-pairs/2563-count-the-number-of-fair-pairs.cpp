class Solution {
public:
long long countNumberOfPairsWithSumStrictlyGreater(vector<int>&nums,int num){
    // strictly greater
    int i = 0;
    int j = nums.size()-1;
    long long ans = 0;
    while(j>i){
        if(nums[i]+nums[j]>num){
            ans = ans + j-i;
            j--;
        }else{
            i++;
        }
    }
    return ans;
}
long long countNumberOfPairsWithSumGreater(vector<int>&nums,int num){
    int i = 0;
    int j = nums.size()-1;
    long long ans = 0;
    while(j>i){
        if(nums[i]+nums[j]>=num){
            ans = ans + j-i;
            j--;
        }else{
            i++;
        }
    }
    return ans;
}
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long  ans1 = countNumberOfPairsWithSumStrictlyGreater(nums,upper);
        long long ans2 = countNumberOfPairsWithSumGreater(nums,lower);
        return ans2-ans1;
    }
};