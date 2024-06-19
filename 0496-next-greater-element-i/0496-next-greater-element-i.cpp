#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        vector<int> stack;
        
        for (int num : nums2) {
            while (!stack.empty() && stack.back() < num) {
                nextGreater[stack.back()] = num;
                stack.pop_back();
            }
            stack.push_back(num);
        }
        
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater.count(num) ? nextGreater[num] : -1);
        }
        
        return result;
    }
};
