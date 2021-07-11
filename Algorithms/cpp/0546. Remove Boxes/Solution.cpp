// https://leetcode-cn.com/problems/remove-boxes/

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        vector<vector<vector<int> > >dp(boxes.size(), vector<vector<int> >(boxes.size(), vector<int>(boxes.size(), -1)));
        function<int(int, int, int)> recur;
        recur = [&](int l, int r, int k) -> int {
            if(l > r) return 0;
            if(dp[l][r][k] == -1){
                dp[l][r][k] = recur(l, r - 1, 0) + (k + 1)*(k + 1); // 清空右边和boxes[r]相等的存积盒子
                for(int i = l; i < r; i++){
                    if(boxes[i] == boxes[r]){
                        // 若找到了boxes[i]和右边的相等，试着把[i+1, r]区间切出来处理，这样剩下的区间的k多了一个
                        dp[l][r][k] = max(dp[l][r][k], recur(l, i, k + 1) + recur(i + 1, r - 1, 0));
                    }
                }
            }
            return dp[l][r][k];
        };
        return recur(0, boxes.size() - 1, 0);
    }
};