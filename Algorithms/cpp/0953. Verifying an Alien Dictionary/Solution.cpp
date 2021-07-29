// https://leetcode-cn.com/problems/verifying-an-alien-dictionary/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if(words.size() <= 1) return true;
        map<char, int> morder;
        for(int i = 0; i < order.length(); i++) morder[order[i]] = i;
        auto cmp = [&](string &a, string &b) {
            for(int i = 0; i < a.length(); i++){
                if(i >= b.length()) return true;
                if(a[i] != b[i]) return morder[a[i]] > morder[b[i]];
            }
            return a.length() > b.length();
        };
        for(int i = 0; i < words.size() - 1; i++){
            if(cmp(words[i], words[i + 1])) return false;
        }
        return true;
    }
};