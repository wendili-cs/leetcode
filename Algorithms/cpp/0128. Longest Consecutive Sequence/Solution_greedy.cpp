// https://leetcode-cn.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max_cnt = 1, cnt = 1, len = nums.size();
        if(len <= 1) return len;
        int last_one = nums[0];
        for(int i = 1; i < len; i++){
            if(last_one + 1 == nums[i]){
                cnt++;
                max_cnt = max(max_cnt, cnt);
            }
            else if(last_one == nums[i]){
                continue;
            }
            else{
                cnt = 1;
            }
            last_one = nums[i];
        }
        return max_cnt;
    }
};