// https://leetcode-cn.com/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> uset1, uset2;
        for(const int& num:nums1) uset1.emplace(num);
        for(const int& num:nums2) uset2.emplace(num);
        vector<int> res;
        for(auto iter = uset1.begin(); iter != uset1.end(); iter++){
            if(uset2.find(*iter) != uset2.end()) res.push_back(*iter);
        }
        return res;
    }
};