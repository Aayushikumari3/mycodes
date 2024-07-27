class Solution {
public:
     bool areSimilar(vector<vector<int>>& mat, int k) {
        
        vector<vector<int>> v=mat;
        
         while (k!=0){
             
              for (int i=0; i< v.size(); i++){
                  
                  for (int j=1; j< v[0].size(); j++){
                      
                      swap(v[i][j-1], v[i][j]);
                  }
              }
             
             k--;
         }
        
        return (v==mat)? true: false;
    }


    
};