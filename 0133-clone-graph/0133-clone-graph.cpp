/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// class Solution {
// public:
//     Node* cloneGraph(Node* node) {
        
//     }
// };

class Solution {
public:
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        
        // If node is already visited, return its clone
        if (visited.find(node) != visited.end()) return visited[node];
        
        // Create a new node for the clone
        Node* cloneNode = new Node(node->val);
        
        // Mark the node as visited
        visited[node] = cloneNode;
        
        // Clone neighbors recursively
        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }
        
        return cloneNode;
    }
};

  // }
// }