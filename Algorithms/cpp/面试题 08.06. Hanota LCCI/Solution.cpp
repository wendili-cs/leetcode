// https://leetcode-cn.com/problems/hanota-lcci/

class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        function<void(int, vector<int>&, vector<int>&, vector<int>&)> recur;
        recur = [&](int n, vector<int>& X, vector<int>& Y, vector<int>& Z) -> void {
            if(n == 0) return;
            recur(n - 1, X, Z, Y); // 先把所有的从X移到Y上
            Z.push_back(X.back()); // 最底下那个从X直接移动到Z上
            X.pop_back();
            recur(n - 1, Y, X, Z); // 剩下的都在Y上，移动到Z上
        };
        recur(A.size(), A, B, C);
    }
};