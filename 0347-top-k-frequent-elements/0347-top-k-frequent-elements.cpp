
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Use a map to count frequencies
        unordered_map<int, int> freqMap;
        for(int num : nums) {
            freqMap[num]++;
        }
        
        // Use a multiset to sort elements by frequency
        multiset<pair<int, int>, greater<>> sortedElements;
        for(auto& entry : freqMap) {
            sortedElements.insert({entry.second, entry.first});
        }

        // Retrieve the top k frequent elements
        vector<int> ans;
        auto it = sortedElements.begin();
        for(int i = 0; i < k && it != sortedElements.end(); ++i, ++it) {
            ans.push_back(it->second);
        }
        
        return ans;
    }
};

