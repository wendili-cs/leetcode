// https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/description/

class Solution {
public:
    bool splitString(string s) {
        auto remove_zero = [](string t) -> string {
            // remove all the 0s at the beginning
            // "0000987000" -> "987000"
            // "" -> ""
            // "0000" -> "0"
            if(t.empty()) return t;
            int x = 0;
            while(x < t.length() && t[x] == '0') x++;
            if(x == t.length()) return "0"; // all 0s
            return t.substr(x);
        };

        vector<long> nums;
        function<bool(string)> recur;
        recur = [&](string t) -> bool{
            if(t.empty() && nums.size() >= 2) {
                return true;
            }
            for(int i = 1; i <= min((int)t.length(), 10); i++){
                long num = stoll(t.substr(0, i));
                if(nums.empty() || nums.back() == num + 1){
                    nums.push_back(num);
                    if(recur(remove_zero(t.substr(i)))) return true;
                    nums.pop_back();
                }
            }
            return false;
        };
        return recur(remove_zero(s));
    }
};