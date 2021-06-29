// https://leetcode-cn.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        function<void(int)> recur;
        recur = [&](int pos) -> void {
            if(pos == -1) {
                digits.insert(digits.begin(), 1);
                return;
            }
            if(digits[pos] != 9) digits[pos]++;
            else {
                digits[pos] = 0;
                recur(pos - 1);
            }
        };
        recur(len - 1);
        return digits;
    }
};