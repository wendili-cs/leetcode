// https://leetcode-cn.com/problems/palindrome-partitioning/
// https://leetcode.com/problems/palindrome-partitioning/
// 执行用时：100 ms, 在所有 C++ 提交中击败了98.93%的用户
// 内存消耗：48 MB, 在所有 C++ 提交中击败了98.54%的用户


class Solution {
public:
    vector<vector<string>> partition(string s) {
        auto isPalindrome = [&](int l, int r) {
            while(l < r){
                if(s[l] != s[r]) return false;
                l++;
                r--;
            }
            return true;
        };
        vector<string> temp;
        vector<vector<string>> res;
        function<void(int)> recur;
        recur = [&](int idx) -> void {
            if(idx >= s.length()){
                res.push_back(temp);
                return;
            }
            for(int i = idx; i < s.length(); i++){
                if(isPalindrome(idx, i)){
                    temp.push_back(s.substr(idx, i - idx + 1));
                    recur(i + 1);
                    temp.pop_back();
                }
            }
        };
        recur(0);
        return res;
    }
};