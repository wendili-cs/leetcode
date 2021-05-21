// https://leetcode-cn.com/problems/combinations/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> temp;
        function<void(int)> recur;
        recur = [&](int cur) -> void {
            if(temp.size() == k || cur > n){
                if(temp.size() == k) res.push_back(temp);
                return;
            }
            for(int i = cur; i <= n; i++){
                temp.push_back(i);
                recur(i + 1);
                temp.pop_back();
            }
        };
        recur(1);
        return res;
    }
};