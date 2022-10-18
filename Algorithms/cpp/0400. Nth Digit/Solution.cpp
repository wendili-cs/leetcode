// https://leetcode.com/problems/nth-digit/

class Solution {
public:
    int findNthDigit(int n) {
        // 9*1, 90*2, 900*3, ..., nums_num*num_len
        long num_len = 1, nums_num = 9;
        while(n > nums_num*num_len){
            n -= nums_num*num_len;
            nums_num *= 10;
            num_len++;
        }
        int num_shift = n/num_len, digit_shift = n%num_len;
        // nums_num/9-1 -> start count number
        // digit_shift!=0 -> if not 0, then shift to next number
        string cur_num = to_string(nums_num/9 - 1 + num_shift + (digit_shift != 0));
        // cout << cur_num << " " << digit_shift << endl;
        return digit_shift == 0 ? cur_num.back() - '0' : cur_num[digit_shift - 1] - '0';
    }
};