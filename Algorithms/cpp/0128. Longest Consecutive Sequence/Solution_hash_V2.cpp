// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 1;
        for(int it:s){
            if(s.find(it - 1) == s.end()){
                // first element
                int cur = 1, num = it;
                while(s.find(num + 1) != s.end()){
                    cur++;
                    res = max(res, cur);
                    num++;
                }
            }
        }
        return res;
    }
};