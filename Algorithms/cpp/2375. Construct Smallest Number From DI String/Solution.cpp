// https://leetcode.com/problems/construct-smallest-number-from-di-string/

class Solution {
public:
    string smallestNumber(string pattern) {
        char c = '1';
        string res;
        int n = pattern.size() + 1;
        for(int i = 0; i < n; i++){
            res.push_back(c++);
        }
        for(int i = 0; i < n - 1; i++){
            if(pattern[i] == 'D'){
                int j = i;
                while(j < n - 1 && pattern[j] == 'D') j++;
                reverse(res.begin() + i, res.begin() + j + 1);
                i = j;
            }
        }
        return res;
    }
};