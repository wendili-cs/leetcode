// https://leetcode.com/problems/gray-code/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = {0, 1};
        function<void(int)> recur;
        recur = [&](int x) -> void {
            if(x == 1) return;
            recur(x - 1);
            int nbit = 1 << (x - 1);
            for(int i = res.size() - 1; i >= 0; i--){
                res.push_back(nbit | res[i]);
            }
        };
        recur(n);
        return res;
    }
};