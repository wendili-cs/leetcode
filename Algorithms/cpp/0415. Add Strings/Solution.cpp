// https://leetcode-cn.com/problems/add-strings/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int idx_1 = num1.length() - 1, idx_2 = num2.length() - 1;
        bool flag = false;
        string res;
        while(idx_1 >=0 || idx_2 >= 0 || flag){
            int temp_sum = (int)flag;
            flag = false;
            if(idx_1 >= 0){
                temp_sum += (int)(num1[idx_1] - '0');
                idx_1--;
            }
            if(idx_2 >= 0){
                temp_sum += (int)(num2[idx_2] - '0');
                idx_2--;
            }
            flag = temp_sum >= 10? true : false;
            temp_sum = temp_sum % 10;
            res = to_string(temp_sum) + res;
        }

        return res;
    }
};