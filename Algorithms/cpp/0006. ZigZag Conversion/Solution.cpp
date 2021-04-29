// https://leetcode-cn.com/problems/zigzag-conversion/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string res;
        int s_len = s.length();
        int loop_len = (2*numRows - 2);
        for(int dev = 0; dev < numRows; dev++){
            for(int loop_iter = 0; loop_iter < (s_len/loop_len) + 1; loop_iter++){
            
                int left_idx = loop_iter*loop_len + dev, right_idx = (loop_iter + 1)*loop_len - dev;
                if(left_idx < s_len){ res += s[left_idx]; }
                if(right_idx < s_len && right_idx != left_idx && dev != 0){ res += s[right_idx]; }
            }
        }
        return res;
    }
};