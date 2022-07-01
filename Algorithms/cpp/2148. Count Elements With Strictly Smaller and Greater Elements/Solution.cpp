// https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/

class Solution {
public:
    int countElements(vector<int>& nums) {
        map<int, int> mp;
        for(int& num:nums) mp[num]++;
        if(mp.begin()->first == mp.rbegin()->first) return nums.size() - mp.begin()->second;
        return nums.size() - mp.begin()->second - mp.rbegin()->second;
    }
};