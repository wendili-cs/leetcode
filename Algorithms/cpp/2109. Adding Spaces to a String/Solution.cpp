// https://leetcode.com/problems/adding-spaces-to-a-string/

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res;
        int add = 0;
        for(int i = 0; i < s.length(); i++){
            if(add < spaces.size() && i == spaces[add]){
                res.push_back(' ');
                add++;
            }
            res.push_back(s[i]);
        }
        return res;
    }
};