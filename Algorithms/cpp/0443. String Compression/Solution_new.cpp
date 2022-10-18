// https://leetcode.com/problems/string-compression/

class Solution {
public:
    int compress(vector<char>& chars) {
        char cur = chars.back(); // a non-letter char
        int l = 0, r = 0, cnt = 0;
        while(r < chars.size()){
            while(r < chars.size() && chars[l] == chars[r]){
                r++;
                cnt++;
            }
            chars.erase(chars.begin() + l + 1, chars.begin() + r);
            r = l + 1;
            if(cnt > 1){
                while(cnt > 0){
                    chars.insert(chars.begin() + l + 1, cnt%10 + '0');
                    cnt /= 10;
                    r++;
                }
            }
            cnt = 0;
            l = r;
        }
        return chars.size();
    }
};