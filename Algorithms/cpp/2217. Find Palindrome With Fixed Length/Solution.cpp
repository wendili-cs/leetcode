// https://leetcode.com/problems/find-palindrome-with-fixed-length/

class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> res(queries.size());
        long long base = powl(10, (intLength + 1)/2 - 1);
        for(int i = 0; i < queries.size(); i++){
            long long new_base = base + queries[i] - 1;
            if((int)log10(new_base) != (int)log10(base)){
                res[i] = -1;
                continue;
            }
            string str_num = to_string(new_base);
            for(int j = intLength/2 - 1; j >= 0; j--){
                str_num.push_back(str_num[j]);
            }
            res[i] = stoll(str_num);
        }
        return res;
    }
};