// https://leetcode.com/problems/clone-graph
// https://www.youtube.com/watch?v=mQeF6bN8hMk

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

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        
        std::unordered_map<Node*, Node*> cache;
        std::unordered_set<Node*> visited;
        return cloneGraph(node, cache, visited);
    }
    
    Node* cloneGraph(Node* node, unordered_map<Node*,Node*>& cache, unordered_set<Node*>& visited) {
        if (visited.find(node) != visited.end()) {
            return cache[node];
        }
        visited.insert(node);
        
        if (cache.find(node) == cache.end()) {
            cache[node] = new Node(node->val);
        }
        
        for (const auto& item : node->neighbors) {
            cache[node]->neighbors.push_back(cloneGraph(item, cache, visited));
        }
        
        return cache[node];
    }
};