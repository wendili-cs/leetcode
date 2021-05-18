// https://leetcode-cn.com/problems/remove-duplicate-letters/

// 思路：遇到一个新字符：如果比栈顶小 && 并且在新字符后面还有和栈顶一样的 -> 弹出栈顶的字符
class Solution {
public:
    string removeDuplicateLetters(string s) {
        if(s.length() <= 1) return s;
        unordered_map<char, int> umap;
        for(int i = 0; i < s.length(); i++){
            umap[s[i]] = i;
        }
        vector<char> stk;
        vector<bool> cnt(26, false);
        // stk.push_back(s[0]);
        for(int i = 0; i < s.length(); i++){
            if(cnt[s[i] - 'a']) continue;
            while(!stk.empty() && stk.back() > s[i] && umap[stk.back()] > i){
                cnt[stk.back() - 'a'] = false;
                stk.pop_back();
            }
            stk.push_back(s[i]);
            cnt[s[i] - 'a'] = true;
        }
        return string(stk.begin(), stk.end());
    }
};