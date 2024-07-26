class Solution {
public:
    // Function to find the maximum sum of heights for all possible partitions.
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long ans = 0; // Initialize the answer to 0.
        int n = maxHeights.size(); // Get the number of elements in the input array.
        
        // Iterate through each element in the input array.
        for (int i = 0; i < n; ++i) {
            vector<int> H(n); // Create a temporary array to store heights.
            H[i] = maxHeights[i]; // Set the current height as the maximum height for this partition.
            
            // Calculate heights for the left part of the partition.
            for (int j = i - 1; j >= 0; --j) {
                H[j] = min(maxHeights[j], H[j + 1]); // Choose the minimum of the current height and the height to the right.
            }
            
            // Calculate heights for the right part of the partition.
            for (int j = i + 1; j < n; ++j) {
                H[j] = min(maxHeights[j], H[j - 1]); // Choose the minimum of the current height and the height to the left.
            }
            
            // Calculate the sum of heights for this partition and update the answer if it's greater.
            ans = max(ans, accumulate(H.begin(), H.end(), 0LL));
        }
        
        return ans; // Return the maximum sum of heights.
    }
};