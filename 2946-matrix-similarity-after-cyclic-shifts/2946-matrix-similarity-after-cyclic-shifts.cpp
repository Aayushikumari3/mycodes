class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        // Create a copy of the matrix to perform operations on
        vector<vector<int>> v = mat;
        
        // Perform k column-wise left rotations
        while (k != 0) {
            for (int i = 0; i < m; i++) {
                // Temporarily store the first element of the row
                int firstElement = v[i][0];
                
                // Shift all elements in the row to the left
                for (int j = 1; j < n; j++) {
                    v[i][j - 1] = v[i][j];
                }
                
                // Move the first element to the end of the row
                v[i][n - 1] = firstElement;
            }
            k--;
        }
        
        // Check if the modified matrix v is the same as the original matrix mat
        return (v == mat);
    }
};
