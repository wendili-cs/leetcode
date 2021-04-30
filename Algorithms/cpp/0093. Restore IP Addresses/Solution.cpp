// https://leetcode-cn.com/problems/restore-ip-addresses/

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string temp;
        int len = s.length();
        if(len < 4 || len > 12) return res;
        for(int i = 1; i < len - 2; i++){
            for(int j = i + 1; j < len - 1; j++){
                for(int k = j + 1; k < len; k++){
                    // 符合规则的放入
                    if((i > 1 && s[0] == '0')||(j - i > 1 && s[i] == '0')||(k - j > 1 && s[j] == '0')||(len - k > 1 && s[k] == '0')) continue;
                    string s1 = s.substr(0, i), s2= s.substr(i, j - i), s3 = s.substr(j, k - j), s4 = s.substr(k, len - k);
                    if(s1.length() > 3||s2.length() > 3||s3.length() > 3||s4.length() > 3) continue;
                    int p1 = stoi(s1), p2 = stoi(s2), p3 = stoi(s3), p4 = stoi(s4);
                    if(p1 <= 255 && p2 <= 255 && p3 <= 255 && p4 <= 255){
                        res.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
                    }
                }
            }
        }
        return res;
    }
};