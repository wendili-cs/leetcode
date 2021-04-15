// https://leetcode-cn.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> L_product(len, 1), R_product(len, 1), res(len);
        for(int i = 1; i < len; i++){
            L_product[i] = L_product[i-1]*nums[i-1];
            R_product[len-i-1] = R_product[len-i]*nums[len-i];
        }

        for(int i = 0; i < len; i++){
            res[i] = L_product[i]*R_product[i];
        }
        return res;
    }
};