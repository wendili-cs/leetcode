// https://leetcode-cn.com/problems/license-key-formatting/

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int cnt = 0;
        string res;
        for(int i = s.length() - 1; i >= 0; i--){
            if(s[i] != '-'){
                res.push_back((s[i] > 'Z'?s[i]-'a'+'A':s[i]));
                cnt++;
                if(cnt % k == 0){
                    res.push_back('-');
                }
            }
        }
        if(res.back() == '-') res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};