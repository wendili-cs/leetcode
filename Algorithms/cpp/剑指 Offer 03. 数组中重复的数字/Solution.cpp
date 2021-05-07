// https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> uset;
        for(const auto& num:nums){
            if(uset.count(num) > 0) return num;
            uset.insert(num);
        }
        return -1;
    }
};