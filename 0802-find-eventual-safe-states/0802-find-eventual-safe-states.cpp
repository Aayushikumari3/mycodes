#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> outdegree(n, 0);
        vector<int> indegree(n, 0);
        
        // Construct the adjacency list and outdegree for each node
        for(int i = 0; i < n; i++) {
            for(int neighbor : graph[i]) {
                adj[neighbor].push_back(i);
                outdegree[i]++;
            }
        }

        // Queue for processing nodes with 0 outdegree
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(outdegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Process nodes
        vector<int> result;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);
            for(int neighbor : adj[node]) {
                outdegree[neighbor]--;
                if(outdegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Sort the result as required
        sort(result.begin(), result.end());
        return result;
    }
};
