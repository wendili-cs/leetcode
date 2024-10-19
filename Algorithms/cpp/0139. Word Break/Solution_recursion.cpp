// https://leetcode.com/problems/word-break/description/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool res = false;
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<bool> visited(s.length(), false);
        function<void(int)> recur;
        recur = [&](int idx) -> void {
            if(idx == s.length()) {
                res = true;
                return;
            }
            if(!visited[idx]){ // 避免重复地计算recur(idx)
                visited[idx] = true;
                for(int len = 1; len <= s.length() - idx; len++){
                    if(st.find(s.substr(idx, len)) != st.end()){
                        recur(idx + len);
                    }
                }
            }
        };
        recur(0);
        return res;
    }
};