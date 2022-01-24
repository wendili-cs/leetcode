// https://leetcode.com/problems/group-shifted-strings/

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        auto to_nums = [&](string& s) -> string {
            string ret = "x";
            for(int i = 1; i < s.length(); i++){
                int dis = s[i] - s[i - 1];
                ret.push_back('0' + (dis<0?dis+26:dis));
            }
            return ret;
        };
        map<string, vector<string>> mp;
        for(auto& str:strings){
            mp[to_nums(str)].push_back(str);
        }
        vector<vector<string>> res;
        for(auto it:mp){
            res.push_back(it.second);
        }
        return res;
    }
};