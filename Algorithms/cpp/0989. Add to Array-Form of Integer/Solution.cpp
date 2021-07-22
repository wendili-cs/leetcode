// https://leetcode-cn.com/problems/add-to-array-form-of-integer/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int idx = num.size() - 1, sign = 0;
        vector<int> res(num.size(), 0);
        while(k > 0 || idx >= 0 || sign){
            int remain = k%10;
            k /= 10;
            int dsum = remain + (idx>=0?num[idx]:0) + sign;
            if(idx < 0){
                res.insert(res.begin(), dsum%10);
            }
            else{
                res[idx] = dsum%10;
                idx--;
            }
            sign = dsum/10;
        }
        return res;
    }
};