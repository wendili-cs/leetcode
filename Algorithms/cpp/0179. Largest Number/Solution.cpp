// https://leetcode-cn.com/problems/largest-number/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for(auto &num:nums) strs.push_back(to_string(num));
        sort(strs.begin(), strs.end(), [](string& a, string& b) {return a + b > b + a;});
        string res;
        for(string &str:strs) res += str;
        return res[0] == '0'?"0":res;
    }
};