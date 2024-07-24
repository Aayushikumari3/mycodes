class Solution {
public:

//    void dfs(int row,int col,vector<vector<int>> &vis,vector<pair<int,int>> &vec,int row0,int col0,vector<vector<char>>& grid)
//     {
       
//     }
    
    int numIslands(vector<vector<char>>& grid) {
       int n=grid.size();
        int m=grid[0].size();
      int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(grid[i][j]=='1' && !vis[i][j]){
                  count++;
                  queue<pair<int,int>>q;
                  q.push({i,j});
                  vis[i][j]=1;
                  while(!q.empty()){
                      int r=q.front().first;
                      int c=q.front().second;
                      q.pop();
                  
                  for(int i=0;i<4;i++){
                      int nx=r+dx[i];
                      int ny=c+dy[i];
                      
                      if(nx>=0 &&ny>=0 &&nx<n && ny<m && !vis[nx][ny] && grid[nx][ny]=='1'){
                          q.push({nx,ny});
                          vis[nx][ny]=1;
                      }
                  }
                  
                  
              }
            }
        }
        
       
}
         return count;
    }
};


//??
