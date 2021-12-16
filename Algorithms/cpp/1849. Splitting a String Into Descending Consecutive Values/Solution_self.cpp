// https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/

class Solution {
public:
    bool splitString(string s) {
        if(s.length() == 1) return false;
        function<bool(int, int, long)> recur;
        recur = [&](int l, int depth, long expected) -> bool {
            int ret = false;
            if(l == s.length() && depth >= 2) return true;
            for(int i = l; i < s.length() && !ret; i++){
                if(i - l >= 11) 
                    break;
                long cur = stoll(s.substr(l, i - l + 1));
                if(expected == cur || expected == -1){
                    int j = i + 1;
                    while(j < s.length() - 1 && s[j] == '0') j++;
                    ret = ret || recur(j, depth + 1, cur - 1);
                }
            }
            return ret;
        };
        int start_idx = 0;
        while(start_idx < s.length() && s[start_idx] == '0') start_idx++;
        return recur(start_idx, 0, -1);
    }
};