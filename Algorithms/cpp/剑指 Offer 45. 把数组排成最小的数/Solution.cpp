// https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/

class Solution {
public:
    static bool cmp(string &a, string &b) {return a + b < b + a;}
    string minNumber(vector<int>& nums) {
        vector<string> nums_str;
        for(const int& num:nums) nums_str.push_back(to_string(num));
        sort(nums_str.begin(), nums_str.end(), cmp);
        string res;
        for(const string& s:nums_str) res += s;
        return res;
    }
};