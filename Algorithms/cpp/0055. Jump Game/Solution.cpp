// https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur_max = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i <= cur_max){
                cur_max = max(cur_max, nums[i] + i);
            }
        }
        return cur_max >= nums.size() - 1;
    }
};