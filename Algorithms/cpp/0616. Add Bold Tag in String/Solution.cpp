// https://leetcode.com/problems/add-bold-tag-in-string/

class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        vector<bool> masks(s.length(), false);
        auto find_all = [&](string word) {
            vector<int> ret;
            int index = s.find(word);
            while(index != s.npos) {
                ret.push_back(index);
                index = s.find(word, index + 1);
            }
            return ret;
        };
        auto update_mask = [&](vector<int> begins, int len) {
            for(int begin:begins){
                for(int i = 0; i < len; i++) masks[begin + i] = true;
            }
        };
        
        for(string &word:words){
            vector<int> begins = find_all(word);
            update_mask(begins, word.length());
        }
        
        string res;
        for(int i = 0; i < s.length(); i++){
            if(masks[i] && (i == 0 || !masks[i - 1])) res += "<b>";
            res.push_back(s[i]);
            if(masks[i] && (i == s.length() - 1 || !masks[i + 1])) res += "</b>";
        }
        
        return res;
    }
};