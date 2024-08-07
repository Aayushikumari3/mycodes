class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        int left = (n + 1) / 2;  // Number of elements in the left half

        int low = 0, high = n1;
        
        while (low <= high) {
            int mid1 = (low + high) / 2;
            int mid2 = left - mid1;

            int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
            int r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];

            if (l1 <= r2 && l2 <= r1) {
                // Correct partitions found
                if (n % 2 == 1) {
                    // Total elements are odd
                    return (double)max(l1, l2);
                } else {
                    // Total elements are even
                    return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
                }
            } else if (l1 > r2) {
                // Adjust the partition in nums1 to the left
                high = mid1 - 1;
            } else {
                // Adjust the partition in nums1 to the right
                low = mid1 + 1;
            }
        }

        // Should never reach here if arrays are non-empty and properly sorted
        throw invalid_argument("Input arrays are not sorted.");
    }
};
