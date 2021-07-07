// https://leetcode-cn.com/problems/valid-triangle-number/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size(), res = 0;
        for(int i = len - 1; i > 0; i--){
            int l = 0, r = i - 1;
            while(l < r){
                if(nums[l] + nums[r] > nums[i]){
                    // l从当前位置滑动到r-1均可，这个时候r固定不变所以不会算重复
                    res += r - l;
                    r--;
                }
                else l++;
            }
        }
        return res;
    }
};