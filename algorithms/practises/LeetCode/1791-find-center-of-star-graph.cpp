// https://leetcode.com/problems/find-center-of-star-graph

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        std::vector<int> graph(edges.size() + 2);
        for (const auto& node : edges) {
            if (++graph[node[0]] >= 2) {
                return node[0];
            }
            
            if (++graph[node[1]] >= 2) {
                return node[1];
            }            
        }
        return -1;
    }
};