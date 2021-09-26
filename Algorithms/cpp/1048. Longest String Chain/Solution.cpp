// https://leetcode.com/problems/longest-string-chain/

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dp;
        unordered_set<string> wordset;
        for(string& word:words) wordset.insert(word);
        function<int(string&)> dfs;
        dfs = [&](string& cur) -> int {
            if(dp.find(cur) != dp.end()) return dp[cur];
            int ret = 1;
            for(int i = 0; i < cur.length(); i++){
                string temp = cur.substr(0, i) + cur.substr(i + 1);
                if(wordset.find(temp) != wordset.end()){
                    int depth = 1 + dfs(temp);
                    ret = max(depth, ret);
                }
            }
            dp[cur] = ret;
            return dp[cur];
        };
        
        int res = 0;
        for(string& word:words){
            res = max(res, dfs(word));
        }
        return res;
    }
};