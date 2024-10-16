// https://leetcode.com/problems/zigzag-conversion/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int len = s.length(), loop_len = 2*numRows - 2;
        string res;
        for(int i = 0; i < numRows; i++){ // i是行数
            for(int j = 0; j < len/loop_len + 1; j++){ // j是循环个数
                // 0   6    12    18
                // 1 5 7 11 13 17 19
                // 2 4 8 10 14 16 20
                // 3   9    15
                // 第i行有两个，left和right，它们如果重复则只加入一个
                // 第0行是没有最后那个数字的，因为它被分到了下一个loop，所以添加s[right]的条件多一个i != 0
                int left = loop_len*j + i, right = loop_len*(j + 1) - i;
                if(left < len) res += s[left];
                if(i != 0 && right < len && left != right) res += s[right];
            }
        }
        return res;
    }
};