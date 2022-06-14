// https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int res = 0, cur_num = -1;
        for(int i = 0; i < nums.size(); i++){
            if(cur_num == nums[i] && (i+res)&1){
                res++;
            }
            else{
                cur_num = nums[i];
            }
        }
        return (nums.size() - res)&1?res+1:res;
    }
};