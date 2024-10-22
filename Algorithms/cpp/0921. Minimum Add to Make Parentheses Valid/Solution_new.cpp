// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0, res = 0;
        for(char &c:s){
            if(c == '('){
                cnt++;
            }
            else{
                cnt--;
                if(cnt < 0) res = max(res, -cnt); // 需要补这些"("
            }
        }
        // 我们补完之后，多出来了res+cnt个"("。要再补上同数量的")"
        if(res + cnt > 0) res += res + cnt;
        return res;
    }
};