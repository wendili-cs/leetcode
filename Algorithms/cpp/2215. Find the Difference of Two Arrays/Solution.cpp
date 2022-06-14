// https://leetcode.com/problems/find-the-difference-of-two-arrays/

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res(2, vector<int>());
        unordered_set<int> s1, s2;
        for(int& num:nums1) s1.insert(num);
        for(int& num:nums2) s2.insert(num);
        for(auto it:s1){
            if(s2.find(it)==s2.end()) res[0].push_back(it);
        }
        for(auto it:s2){
            if(s1.find(it)==s1.end()) res[1].push_back(it);
        }
        return res;
    }
};