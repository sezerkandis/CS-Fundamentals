//https://leetcode.com/problems/find-if-path-exists-in-graph/submissions/

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        std::unordered_map<int, vector<int>> graph;
        for (const auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        // printing array
        /*for (int i = 0; i < edges.size(); i++) {
            std::vector g = graph[i];
            std::cout << "graph[" << i << "] = {";
            for (int j = 0; j < g.size(); j++) {
                std::cout << " " << g[j];
            }
            std::cout << " }" << std::endl;
        }*/
        
        std::vector<bool> visited(n, false);
        std::queue<int> q;
        q.push(start);
        visited[start] = true;
        
        while(!q.empty()) {
            int current_vertex = q.front();
            q.pop();
            
            //std::cout << "current_vertex: " << current_vertex << ", end: " << end << std::endl;
            if (current_vertex == end) {
                return true;
            }
            
            for (const auto& node : graph[current_vertex]) {
                //std::cout << "node: " << node << ", visited[node]: " << visited[node] << std::endl;
                if (!visited[node]) {
                    visited[node] = true;
                    q.push(node);
                }
            }
        }
        
        return false; 
    }
};