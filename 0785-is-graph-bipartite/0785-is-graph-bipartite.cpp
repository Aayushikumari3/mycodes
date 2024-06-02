class Solution {
public:
    bool dfs(int node,int col,int color[],vector<vector<int>>& adj)
    {
        color[node]=col;
        
        for(auto it:adj[node])
        {
            if(color[it]==-1)
            {
                if(dfs(it,!col,color,adj)==false)
                    return false;
            }
            else if(col==color[it])
                return false;
        }
        return true;
    }
    
    
        bool isBipartite(vector<vector<int>>& graph) {
       

        int n=graph.size();
        
    vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }
        
            int color[n];
	    for(int i = 0;i<n;i++) color[i] = -1;
        
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(dfs(i,0,color,adj)==false)
                    return false;
            }
    
        }
       return true; 
    }
};
// class Solution {
// public:
//     bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& graph) {
//         color[node] = col;
        
//         for (int neighbor : graph[node]) {
//             if (color[neighbor] == -1) {
//                 if (!dfs(neighbor, !col, color, graph))
//                     return false;
//             } else if (col == color[neighbor]) {
//                 return false;
//             }
//         }
//         return true;
//     }

//     bool isBipartite(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int> color(n, -1); // Initialize color array
        
//         for (int i = 0; i < n; ++i) {
//             if (color[i] == -1) {
//                 if (!dfs(i, 0, color, graph))
//                     return false;
//             }
//         }
//         return true; 
//     }
// };
