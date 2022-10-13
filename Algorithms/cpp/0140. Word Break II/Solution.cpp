// https://leetcode.com/problems/word-break-ii/

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(string& word:wordDict){
            st.insert(word);
        }
        string tmp;
        vector<string> res;
        function<void(int)> recur;
        recur = [&](int idx) -> void {
            if(idx >= s.length()) res.push_back(tmp);
            for(int i = idx; i < s.length(); i++){
                string sub = s.substr(idx, i - idx + 1);
                if(st.find(sub) != st.end()){
                    string old_tmp = tmp;
                    tmp = tmp.empty() ? sub : tmp + " " + sub;
                    recur(i + 1);
                    tmp = old_tmp;
                }
            }
        };
        recur(0);
        return res;
    }
};