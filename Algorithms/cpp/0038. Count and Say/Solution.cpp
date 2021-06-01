// https://leetcode-cn.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string last = countAndSay(n - 1);
        int idx1 = 0, idx2 = 0;
        string res = "";
        while(idx2 < last.length()){
            if(last[idx1] != last[idx2]){
                res += to_string(idx2 - idx1);
                res += last[idx1];
                // last.insert(idx1, to_string(idx2 - idx1));
                // last.erase(idx1 + 2, idx2 - idx1 - 1);
                idx1 = idx2;
            }
            idx2++;
        }
        res += to_string(idx2 - idx1);
        res += last[idx1];
        return res;
    }
};