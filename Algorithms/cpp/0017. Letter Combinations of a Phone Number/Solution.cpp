// https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> d2a;
        vector<string> alpha_map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for(int i = 2; i <= 9; i++){
            d2a.emplace((char)(i + '0'), alpha_map[i - 2]);
        }
        vector<string> res;
        string temp;
        function<void(string)> recurr;
        recurr = [&](string s) -> void {
            if(s.empty()){
                if(!temp.empty()) res.push_back(temp);
                return;
            }
            for(const char& c:d2a[s[0]]){
                temp += c;
                recurr(s.substr(1));
                temp.pop_back();
            }

        };
        recurr(digits);
        return res;
    }
};