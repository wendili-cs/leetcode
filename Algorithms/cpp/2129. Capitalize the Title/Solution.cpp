// https://leetcode.com/problems/capitalize-the-title/

class Solution {
public:
    string capitalizeTitle(string title) {
        title.push_back(' ');
        string res;
        int l = 0, r = 0, n = title.length();
        while(l < n){
            r = l;
            while(title[r] != ' ') r++;
            string tmp = title.substr(l, r - l);
            for(int i = 0; i < tmp.length(); i++){
                if(i == 0 && tmp.length() > 2) tmp[i] = toupper(tmp[i]);
                else tmp[i] = tolower(tmp[i]);
            }
            res += tmp + " ";
            l = r + 1;
        }
        res.pop_back();
        return res;
    }
};