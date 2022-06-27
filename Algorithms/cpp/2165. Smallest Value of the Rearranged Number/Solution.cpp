// https://leetcode.com/problems/smallest-value-of-the-rearranged-number/

class Solution {
public:
    long long smallestNumber(long long num) {
        string str_num;
        bool is_positive = true;
        if(num > 0){
            str_num = to_string(num);
        }
        else if(num < 0){
            str_num = to_string(-num);
            is_positive = false;
        }
        else return 0;
        if(is_positive){
            sort(str_num.begin(), str_num.end());
            if(str_num[0] == '0'){
                int idx = str_num.find_first_not_of('0');
                swap(str_num[0], str_num[idx]);
            }
        }
        else{
            sort(str_num.begin(), str_num.end(), [](char &a, char &b){return a > b;});
            str_num.insert(0, 1, '-');
        }
        return stoll(str_num);
    }
};