// https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        vector<int> cnt(3, 0);
        for(int i = 0; i < n; i++){
            cnt[s[i] - 'a']++;
        }
        for(int i = 0; i < 3; i++) if (cnt[i] < k) return -1;
        // 一个反向滑动窗口，cnt[i]记录的是滑动窗口外的字母数量
        int len = 0, l = 0;
        for(int r = 0; r < n; r++){
            cnt[s[r] - 'a']--; // s[r]被除外
            while(cnt[0] < k || cnt[1] < k || cnt[2] < k){
                cnt[s[l] - 'a']++; // s[l]被加入
                l++;
            }
            len = max(len, r - l + 1); // len是最后保留部分的长度
        }
        return n - len;
    }
};