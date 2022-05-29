// https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {        
        if (n == 1) {
            return 1;
        }
        
        std::vector<int> count (n + 1, 0);
        for (const auto& item : trust) {
            count[item[0]]--;
            count[item[1]]++;
        }
        
        auto it = std::find(count.begin(), count.end(), n-1);
        if (it != count.end()) {
            return std::distance(count.begin(), it);
        }
        
        return -1;
    }
};