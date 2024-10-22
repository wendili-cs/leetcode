// https://leetcode-cn.com/problems/jump-game/
// https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        function<bool(int)> dfs;
        dfs = [&](int x) -> bool {
            if(x >= nums.size() - 1) return true;
            for(int y = x + 1; y <= x + nums[x]; y++){
                if(!visited[y]){
                    if(dfs(y)) return true;
                    visited[y] = true;
                }
            }
            return false;
        };
        return dfs(0);
    }
};