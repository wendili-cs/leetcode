// https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/

class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        int len = s.length();
        function<void(int)> recurr;
        recurr = [&](int x) -> void {
            if(x == len){
                res.push_back(s);
                return;
            }
            unordered_set<char> uset;
            for(int i = x; i < len; i++){
                if(uset.count(s[i]) > 0) continue;
                uset.insert(s[i]);
                swap(s[i], s[x]);
                recurr(x + 1);
                swap(s[i], s[x]);
            }
        };
        recurr(0);
        return res;
    }
};