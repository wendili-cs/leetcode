// https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/

class Solution {
public:
    string replaceSpace(string s) {
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                s.erase(i, 1);
                s.insert(i, "%20");
            }
        }
        return s;
    }
};