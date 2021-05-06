// https://leetcode-cn.com/problems/jump-game/
// 超时

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        function<bool(int)> recurr;
        recurr = [&](int idx) -> bool {
            if(idx >= len) return false;
            else if(idx == len - 1) return true;
            for(int i = nums[idx]; i >= 1; i--){
                if(idx + i < len){
                    if(recurr(idx + i)) return true;
                }
            }
            return false;
        };
        return recurr(0);
    }
};