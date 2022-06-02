// https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/

class Solution {
public:
    bool digitCount(string num) {
        vector<int> cnt(26, 0);
        for(auto x:num){
            cnt[x - '0']++;
        }
        for(int i = 0; i < num.length(); i++){
            if(num[i] - '0' != cnt[i]) return false;
        }
        return true;
    }
};