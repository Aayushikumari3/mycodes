// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> ans;
      
//         int l=0,r=0;        //  l=left pointer, r=right pointer
        
//         priority_queue<pair<int,int>> pq;       
        
//         if(k>nums.size()) return ans;
        
//         while(r<nums.size()){
//             if(r-l+1<k){
//                 pq.push(make_pair(nums[r],r));
//                 r++;
//             }
//             else{
//                 if(r<nums.size()) pq.push(make_pair(nums[r],r));
                
//                 if(l<=pq.top().second)
//                     ans.push_back(pq.top().first);
//                 else{
//                     while(l>pq.top().second){
//                         pq.pop();
//                     }
//                     ans.push_back(pq.top().first);
//                 }
                
//                 l++;
//                 r++;
                
//             }
//         }
//         return ans;
//     }
// };
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq; // stores indices

        for (int i = 0; i < nums.size(); ++i) {
            // Remove indices that are out of the current window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // Remove elements from the deque that are less than the current element
            // because they are not useful anymore
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Add the current element at the back of the deque
            dq.push_back(i);

            // The window has reached size k, so record the max in the current window
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
