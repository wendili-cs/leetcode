// https://leetcode-cn.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length() < s1.length()) return false;
        vector<int> s1_cnt(26, 0), s2_cnt(26, 0);
        int len1 = s1.length(), len2 = s2.length();
        for(int i = 0; i < len1; i++){
            s1_cnt[s1[i] - 'a']++;
            s2_cnt[s2[i] - 'a']++;
        }
        if(s1_cnt == s2_cnt) return true;
        for(int i = len1; i < len2; i++){
            // 滑动窗口，以s1的长度len1为窗口滑动计算counter
            s2_cnt[s2[i - len1] - 'a']--;
            s2_cnt[s2[i] - 'a']++;
            if(s1_cnt == s2_cnt) return true;
        }
        return false;
    }
};