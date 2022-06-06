// https://leetcode.com/problems/find-the-k-beauty-of-a-number/

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int res = 0;
        for(int i = 0; i < s.length() - k + 1; i++){
            int a = stoi(s.substr(i, k));
            if(a != 0 && num%a == 0) res++;
        }
        return res;
    }
};