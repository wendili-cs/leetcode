// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/

class Solution {
public:
    int maximumLength(string s) {
        auto num_substring = [&](string t) -> int {
            // find how many times string t repeats
            if(t.empty()) return 0;
            int ret = 0, pos = s.find(t);
            while(pos != string::npos){
                ret++;
                pos = s.find(t, pos + 1);
            }
            return ret;
        };
        auto longest_thrice = [&](char c, int rep) -> int {
            // find maximum special string that repeats thrice
            int l = 0, r = rep;
            while(l < r){
                int mid = (r - l + 1)/2 + l;
                string tmp = string(mid, c);
                if(num_substring(tmp) >= 3){
                    l = mid;
                }
                else{
                    r = mid - 1;
                }
            }
            return l;
        };
        vector<int> cnter(26, 0); // record maximum continuously repeating times 
        int res = 0, idx = 0;
        for(int i = 1; i < s.length(); i++){
            int letter_idx = s[idx] - 'a';
            if(s[i] == s[i - 1]){
                cnter[letter_idx] = max(cnter[letter_idx], i - idx + 1);
            }
            else{
                idx = i;
                cnter[letter_idx] = max(cnter[letter_idx], 1);
            }
        }
        
        for(int i = 0; i < 26; i++){
            if(cnter[i] > 0) res = max(res, longest_thrice(i + 'a', cnter[i]));
        }
        return res == 0 ? -1 : res;
    }
};