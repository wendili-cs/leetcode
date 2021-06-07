// https://leetcode-cn.com/problems/split-array-largest-sum/

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int l = *max_element(nums.begin(), nums.end()), r = 0;
        for(const int& num:nums) r += num;
        while(l < r){
            int mid = (l + r)/2, temp = 0, cnt = 1;
            for(const int& num:nums){
                if(temp + num > mid){
                    cnt++;
                    temp = 0;
                }
                temp += num;
            }
            if(cnt > m) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};