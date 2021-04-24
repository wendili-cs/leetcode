// https://leetcode-cn.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_len = INT_MAX;
        if(strs.size() == 1) return strs[0];
        for(const auto& str : strs){
            int str_len = str.size();
            min_len = min(str_len, min_len);
        }
        string res;
        auto check_i = [&](int idx, char temp) -> bool {
            for(int i = 1; i < strs.size(); i++){
                if(strs[i][idx] != temp){
                    return false;
                }
            }
            return true;
        };
        for(int idx = 0; idx < min_len; idx++){
            char temp = strs[0][idx];
            if(check_i(idx, temp)){
                res += temp;
            }
            else{
                break;
            }
        }
        return res;
    }
};