
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        
        sort(strs.begin(), strs.end());
        int i = 0;
        int n = strs.size();
        string first = strs[0];
        string last = strs[n - 1];
        
        while (i < first.size() && i < last.size() && first[i] == last[i]) {
            i++;
        }
        
        return first.substr(0, i);
    }
};
