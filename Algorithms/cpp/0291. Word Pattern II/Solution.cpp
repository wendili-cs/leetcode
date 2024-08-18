// https://leetcode.com/problems/word-pattern-ii/

class Solution {
public:
    bool wordPatternMatch(string pattern, string s) {
        int m = pattern.length(), n = s.length();
        unordered_map<char, string> mp;
        unordered_set<string> st;
        function<bool(int, int)> dfs;
        dfs = [&](int x, int y) -> bool {
            if(x == m && y == n) 
            return true;
            if(x == m || y >= n) return false;
            if(mp.find(pattern[x]) != mp.end()){
                int len = mp[pattern[x]].length();
                if(y + len > n || s.substr(y, len) != mp[pattern[x]]) return false;
                return dfs(x + 1, y + len);
            }
            for(int len = 1; len <= n - y; len++){
                string tmp = s.substr(y, len);
                if(st.find(tmp) != st.end()) continue; // already has a char that corresponds to this string
                mp[pattern[x]] = tmp;
                st.insert(tmp);
                if(dfs(x + 1, y + len)) {
                    return true;
                }
                mp.erase(pattern[x]);
                st.erase(tmp);
            }
            return false;
        };
        return dfs(0, 0);
    }
};