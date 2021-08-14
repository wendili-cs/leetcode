// https://leetcode-cn.com/problems/excel-sheet-column-title/

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        int x = 26;
        while(columnNumber > 0){
            columnNumber--;
            res.push_back(columnNumber%x + 'A');
            columnNumber /= x;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};