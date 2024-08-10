// https://leetcode.com/problems/frog-jump/

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_set<int> s(stones.begin(), stones.end());
        map<pair<int,int>, bool> mem;
        function<bool(int, int)> dfs;
        dfs = [&](int start, int lastjump) -> bool {
            if(start == stones.back()) return true; // reach the target
            if(start > stones.back()) return false; // go far than target
            if(s.find(start) == s.end()) return false; // no stone here
            auto p = make_pair(start, lastjump);
            if(mem.find(p) == mem.end()){
                for(int jump = lastjump - 1; jump <= lastjump + 1; jump++){
                    if(jump > 0){
                        mem[p] = mem[p] || dfs(start + jump, jump);
                    }
                }
            }
            return mem[p];
        };
        return dfs(0, 0);
    }
};