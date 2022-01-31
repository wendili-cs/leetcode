// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> dict, cnter;
        for(char&c:t) dict[c]++;
        int num_letter = dict.size(), cur_letter = 0, l = 0, r = 0, fl = -1000000, fr = -1; // number of letters to satisify, current state
        while(r < s.length()){
            cnter[s[r]]++;
            if(dict.find(s[r]) != dict.end() && dict[s[r]] == cnter[s[r]]) cur_letter++;
            while(cur_letter == num_letter && l <= r){
                if(fr - fl > r - l){
                    fl = l;
                    fr = r;
                }
                cnter[s[l]]--;
                if(cnter[s[l]] < dict[s[l]]) cur_letter--;
                l++;
            }
            r++;
        }
        return fr == -1?"":s.substr(fl, fr - fl + 1);
    }
};