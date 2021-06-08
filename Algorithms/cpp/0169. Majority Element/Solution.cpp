// https://leetcode-cn.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0], cnt = 0;
        for(const int& num:nums){
            if(res == num) cnt++;
            else{
                cnt--;
                if(cnt < 0){
                    cnt = 1;
                    res = num;
                }
            }
        }
        return res;
    }
};