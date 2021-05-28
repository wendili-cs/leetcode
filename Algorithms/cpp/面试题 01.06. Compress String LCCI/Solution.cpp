// https://leetcode-cn.com/problems/compress-string-lcci/comments/

class Solution {
public:
    string compressString(string S) {
        string s = S;
        for(int i = 0; i < S.length(); i++){
            int j = i + 1;
            if(j == S.length()){
                S.insert(j, 1, '1');
                break;
            }
            if(S[j] == S[i]){
                while(S[j] == S[i]){
                j++;
                }
                S.erase(i + 1, j - i - 1);
                string num = to_string(j - i);
                S.insert(i + 1, num);
                i += num.length();
            }
            else{
                S.insert(i + 1, 1, '1');
                i++;
            }
        }
        return S.length() < s.length()? S:s;
    }
};