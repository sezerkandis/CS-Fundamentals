// https://leetcode.com/problems/course-schedule-ii
// https://www.youtube.com/watch?v=Akt3glAwyfY

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);    
    for(const auto& p : prerequisites)
        graph[p[0]].push_back(p[1]);
 
    // states: 0 = unkonwn, 1 == visiting, 2 = visited
    vector<int> v(numCourses, 0);
    vector<int> ans;
    
    for (int i = 0; i < numCourses; ++i)
        if (dfs(i, graph, v, ans)) return {};
 
    //std::reverse(ans.begin(), ans.end());
    return ans;
  }
private:
  bool dfs(int cur, vector<vector<int>>& graph, vector<int>& v, vector<int>& ans) {
    if (v[cur] == 1) return true;
    if (v[cur] == 2) return false;
 
    v[cur] = 1;
    
    for (const int t : graph[cur])
      if (dfs(t, graph, v, ans)) return true;
    
    v[cur] = 2;
    ans.push_back(cur);
 
    return false;
  }
};