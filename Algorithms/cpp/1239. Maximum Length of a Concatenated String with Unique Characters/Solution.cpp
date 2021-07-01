// https://leetcode-cn.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

// 思路：回溯，用一个int值来表示hash表
class Solution {
public:
    int maxLength(vector<string>& arr) {
        int len = arr.size();
        function<int(int, int)> backtrace;
        backtrace = [&](int p, int used) -> int {
            if(p >= len) return 0;
            int used2 = used;
            for(char c:arr[p]){
                if(used2 & (1 << (c - 'a'))) return backtrace(p + 1, used);
                used2 |= (1 << (c - 'a'));
            }
            return max((int)arr[p].size() + backtrace(p + 1, used2), backtrace(p + 1, used));
        };
        return backtrace(0, 0);
    }
};