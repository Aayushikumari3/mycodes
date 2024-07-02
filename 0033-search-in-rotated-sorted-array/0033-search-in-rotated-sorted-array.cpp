// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//          auto it = find(nums.begin(), nums.end(), target);

//     if (it != nums.end()) {
//         return distance(nums.begin(), it);
//     } else {
//         return -1 ;
//     }
//     }
// };
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0; // Initialize start index of search range
        int high = nums.size() - 1; // Initialize end index of search range
        
        while (low <= high) { // Binary search loop
            int mid = low + (high - low) / 2; // Calculate midpoint
            
            if (nums[mid] == target) { // Target found
                return mid;
            }
            
            if (nums[low] <= nums[mid]) { // Left half is sorted
                if (nums[low] <= target && target <= nums[mid]) { // Target in left sorted half
                    high = mid - 1;
                } else { // Target in right unsorted half
                    low = mid + 1;
                }
            } else { // Right half is sorted
                if (nums[mid] <= target && target <= nums[high]) { // Target in right sorted half
                    low = mid + 1;
                } else { // Target in left unsorted half
                    high = mid - 1;
                }
            }
        }
        
        return -1; // Target not found
    }
};
