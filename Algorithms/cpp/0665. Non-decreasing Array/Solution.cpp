// https://leetcode-cn.com/problems/non-decreasing-array/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return true;
        function<bool(bool)> recur;
        recur = [&](bool flag) -> bool {
            for(int i = 0; i < len - 1; i++){
                if(nums[i] > nums[i + 1]){
                    if(flag) return false;
                    int temp = nums[i];
                    nums[i] = nums[i + 1];
                    if(recur(true)) return true;
                    nums[i + 1] = temp;
                    nums[i] = temp;
                    if(recur(true)) return true;
                    return false;
                }
            }
            return true;
        };
        return recur(false);
    }
};