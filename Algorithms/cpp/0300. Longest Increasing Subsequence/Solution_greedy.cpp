// https://leetcode-cn.com/problems/longest-increasing-subsequence/submissions/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return 1;
        int max_len = 1;
        vector<int> v_min(len + 1);
        v_min[1] = nums[0];
        for(int i = 1; i < len; i++){
            if(nums[i] > v_min[max_len]){
                max_len += 1;
                v_min[max_len] = nums[i];
            }
            else{
                int l = 1, r = max_len, p = 0;
                // v_min是单调函数，所以二分查找
                while(l < r){
                    int m = (l + r)/2;
                    if(v_min[m] < nums[i]){
                        p = m;
                        l = m + 1;
                    }
                    else{
                        r = r - 1;
                    }
                }
                v_min[p + 1] = nums[i];
            }
        }
        return max_len;
    }
};