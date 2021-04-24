// https://leetcode-cn.com/problems/palindrome-partitioning/
// 执行用时：100 ms, 在所有 C++ 提交中击败了98.93%的用户
// 内存消耗：48 MB, 在所有 C++ 提交中击败了98.54%的用户


class Solution {
public:
    vector<vector<string>> partition(string s) {
        int len = s.length();
        vector<vector<string> > res;
        vector<string> temp_list;
        auto isPalindrome = [](string s) {
            int idx_1 = 0, idx_2 = s.size() - 1;
            while (idx_1 < idx_2) {
                if (s[idx_1] != s[idx_2]) {
                    return false;
                }
                idx_1++;
                idx_2--;
            }
            return true;
        };

        function<void(int)> recurr;
        recurr = [&](int idx) -> void {
            if(idx >= len){
                res.push_back(temp_list);
                return;
            }
            for(int L = 1; L < len - idx + 1; L++){
                if(isPalindrome(s.substr(idx, L))){
                    temp_list.push_back(s.substr(idx, L));
                    recurr(idx + L);
                    temp_list.pop_back();
                }
            }
        };

        recurr(0);
        return res;
    }
};