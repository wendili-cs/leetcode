// https://leetcode.com/contest/weekly-contest-373/problems/make-lexicographically-smallest-array-by-swapping-elements/

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int len = nums.size();
        vector<int> tmp(len);
        for(int i = 0; i < len; i++){
            tmp[i] = nums[i];
        }
        sort(tmp.begin(), tmp.end());
        
        int level = 1;
        unordered_map<int,int> n2l; // number to level
        unordered_map<int, multiset<int>> l2s; // level to number set
        for(int i = 0; i < len; i++){
            if(i > 0 && tmp[i] - tmp[i - 1] > limit) level++;
            n2l[tmp[i]] = level;
            l2s[level].insert(tmp[i]);
        }
        
        for(int i = 0; i < len; i++){
            auto it = l2s[n2l[nums[i]]].begin();
            nums[i] = *(it);
            l2s[n2l[nums[i]]].erase(it);
        }
        
        return nums;
    }
};