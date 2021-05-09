// https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/

class Solution {
public:
    string removeDuplicates(string S) {
        S = 'A' + S;
        for(int i = 1; i < S.length() - 1; i++){
            if(S[i] == S[i + 1]){
                S.erase(i, 2);
                i -= 2;
            }
        }
        return S.substr(1); 
    }
};