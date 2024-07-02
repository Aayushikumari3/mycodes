class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       int low=nums[0],n=nums.size(),k=0;
//         while(low<=high)
//         {
//             mid=(low+high)>>1;
//             if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
//                 return nums[mid];
//             else if(nums[mid]<nums[mid+1] || nums[mid]==nums[mid+1])
                
//         }
      for(int i=1;i<n;i++)
        {
            low^=nums[i];        }
        return low;
    }
};