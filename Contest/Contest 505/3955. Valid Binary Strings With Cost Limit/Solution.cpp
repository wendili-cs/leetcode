// https://leetcode.com/problems/valid-binary-strings-with-cost-limit/

class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        string cur;
        vector<string> res;
        function<void(int, int)> backtracking = [&](int idx, int cost) -> void {
            if(idx >= n) {
                // build finish
                res.push_back(cur);
                return;
            }
            if((cur.empty() || cur.back() == '0') && cost + idx <= k){
                // if we can append 1 in next position and the next build is valid
                cur.push_back('1');
                backtracking(idx + 1, cost + idx);
                cur.pop_back();
            }
            // we can always append 0 in next position if current is valid
            cur.push_back('0');
            backtracking(idx + 1, cost);
            cur.pop_back();
        };
        backtracking(0, 0);
        return res;
    }
};