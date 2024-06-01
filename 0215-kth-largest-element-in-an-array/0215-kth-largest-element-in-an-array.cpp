class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
         priority_queue<int> maxHeap;

    // Insert all elements from the vector into the max heap
    for (int num : nums) {
        maxHeap.push(num);
    }
 for (int i = 0; i < k - 1; ++i) {
        maxHeap.pop();
    }

    // The k-th largest element will now be at the top of the max heap
    return maxHeap.top();
    }
};