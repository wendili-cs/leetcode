// https://leetcode-cn.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        vector<int> cnter1(26, 0), cnter2(26, 0);
        for(char& c:s1){
            cnter1[c - 'a']++;
        }
        int len = s1.length();
        for(int i = 0; i < len; i++){
            cnter2[s2[i] - 'a']++;
        }
        if(cnter1 == cnter2) return true;
        for(int i = len; i < s2.length(); i++){
            cnter2[s2[i - len] - 'a']--;
            cnter2[s2[i] - 'a']++;
            if(cnter1 == cnter2) return true;
        }
        return false;
    }
};