// https://leetcode-cn.com/problems/WhsWhI/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        set<int> s;
        for(int& num:nums) s.insert(num);
        for(int& num:nums){
            if(s.find(num - 1) == s.end()){
                int temp = 1, next = num + 1;
                while(s.find(next++) != s.end()) temp++;
                res = max(res, temp);
            }
        }
        return res;
    }
};