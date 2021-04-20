// https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_val = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(min_val > nums[i]){
                min_val = nums[i];
            }
        }
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            res += nums[i] - min_val;
        }
        return res;
    }
};