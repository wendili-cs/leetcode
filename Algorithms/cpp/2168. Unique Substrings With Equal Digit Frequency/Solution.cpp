// https://leetcode.com/problems/unique-substrings-with-equal-digit-frequency/

class Solution {
public:
    int equalDigitFrequency(string s) {
        vector<int> cnter(10, 0);
        auto check = [&]() -> bool { // check whether all digit appears the same number of times
            int ele = 0;
            for(int i = 0; i < 10; i++){
                if(!ele && cnter[i]) ele = cnter[i];
                else if(ele && cnter[i] && cnter[i] != ele) return false;
            }
            return true;
        };
        unordered_set<int> ss; // rolling hash
        // unordered_set<string> ss; // original hash
        for(int i = 0; i < s.length(); i++){
            cnter = vector<int>(10, 0);
            long P = 13, m = 1000000007, s_hash = 0; // rolling hash
            for(int j = i; j < s.length(); j++){
                cnter[s[j] - '0']++;
                s_hash = (s_hash*P + s[j] - '0' + 1)%m; // rolling hash
                if(check()){
                    // ss.insert(s.substr(i, j - i + 1)); // original hash
                    ss.insert(s_hash); // rolling hash
                }
            }
        }
        return ss.size();
    }
};