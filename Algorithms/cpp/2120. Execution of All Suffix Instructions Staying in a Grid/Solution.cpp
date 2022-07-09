// https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> res(s.length(), -1);
        for(int i = 0; i < s.length(); i++){
            int x = startPos[0], y = startPos[1];
            for(int j = i; j < s.length(); j++){
                if(s[j] == 'R') y++;
                else if(s[j] == 'L') y--;
                else if(s[j] == 'D') x++;
                else x--;
                if(x < 0 || x >= n || y < 0 || y >= n){
                    res[i] = j - i;
                    break;
                }
            }
            if(res[i] == -1) res[i] = s.length() - i;
        }
        return res;
    }
};