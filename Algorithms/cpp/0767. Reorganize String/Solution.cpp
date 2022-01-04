// https://leetcode.com/problems/reorganize-string/

class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> cnter;
        int max_cnt = 0;
        for(auto& c:s){
            cnter[c]++;
            max_cnt = max(max_cnt, cnter[c]);
        }
        set<pair<int, int>> cnter2;
        for(auto it:cnter) cnter2.insert(make_pair(-it.second, it.first));
        if(max_cnt > (s.length()+1)/2) return "";
        int i = 0;
        for(auto it:cnter2){
            for(int j = 0; j < -it.first; j++){
                if(i >= s.length()) i = 1;
                s[i] = it.second;
                i += 2;
            }
        }
        return s;
    }
};