// https://leetcode-cn.com/problems/string-compression/

class Solution {
public:
    int compress(vector<char>& chars) {
        int l = 0, r = 0, cnter = 0, len = chars.size();
        char last = chars[0];
        while(r < chars.size()){
            if(chars[l] == chars[r]){
                cnter++;
                r++;
            }
            else if(cnter == 1){
                l = r;
                cnter = 0;
            }
            else{
                chars.erase(chars.begin() + l + 1, chars.begin() + r);
                string s = to_string(cnter);
                for(int i = 0; i < s.length(); i++){
                    chars.insert(chars.begin() + l + 1 + i, s[i]);
                }
                l += s.length() + 1;
                r = l;
                cnter = 0;
            }
        }
        if(cnter != 1){
            chars.erase(chars.begin() + l + 1, chars.end());
            string s = to_string(cnter);
            for(int i = 0; i < s.length(); i++){
                chars.insert(chars.begin() + l + 1 + i, s[i]);
            }
        }
        return chars.size();
    }
};