// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int idx = 0;
        while(true){
            for(string& str:strs){
                if(idx >= str.length() || str[idx] != strs[0][idx]) return strs[0].substr(0, idx);
            }
            idx++;
        }
        return "";
    }
};