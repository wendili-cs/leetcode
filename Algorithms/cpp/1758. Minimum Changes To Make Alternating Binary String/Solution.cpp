// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/

class Solution {
public:
    int minOperations(string s) {
        auto check_ops = [&](int cur) -> int {
            // cur is the starting char, which can be 1 or 0
            int ret = 0;
            for(char c:s){
                if(c - '0' != cur){
                    ret++;
                }
                cur = 1 - cur;
            }
            return ret;
        };
        // check starting with 1 and starting with 0
        return min(check_ops(0), check_ops(1));
    }
};