// https://leetcode-cn.com/problems/arithmetic-slices/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() <= 2) return 0;
        vector<int> diff(nums.size() - 1, 0);
        for(int i = 0; i < diff.size(); i++) diff[i] = nums[i + 1] - nums[i];
        int l = 0, r, res = 0;
        for(r = 1; r < diff.size(); r++){
            if(diff[r] != diff[r - 1]){
                if(r - l >= 2) res += (r - l)*(r - l - 1)/2;
                l = r;
            }
        }
        if(r - l >= 2) res += (r - l)*(r - l - 1)/2;
        return res;
    }
};