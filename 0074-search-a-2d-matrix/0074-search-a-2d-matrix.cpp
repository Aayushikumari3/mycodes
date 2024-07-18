class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     int r=matrix.size();
        int c=matrix[0].size();
        for(int i=0;i<r;i++)
        {
            if(binary_search(matrix[i].begin(),matrix[i].end(),target))
                return true;
        }
        return false;
    }
};