// https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/

class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> res;
        for(char i = s[0]; i <= s[3]; i++){
            for(char j = s[1]; j <= s[4]; j++){
                string t;
                t.push_back(i);
                t.push_back(j);
                res.push_back(t);
            }
        }
        return res;
    }
};