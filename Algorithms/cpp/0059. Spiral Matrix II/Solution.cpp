// https://leetcode-cn.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int cnt = 1, left = 0, right = n - 1, top = 0, bottom = n - 1;
        vector<vector<int> > res(n, vector<int>(n, -1));
        while(cnt <= n*n){
            for(int i = left; i <= right && cnt <= n*n; i++){
                res[top][i] = cnt;
                cnt++;
            }
            top++;
            for(int i = top; i <= bottom && cnt <= n*n; i++){
                res[i][right] = cnt;
                cnt++;
            }
            right--;
            for(int i = right; i >= left && cnt <= n*n; i--){
                res[bottom][i] = cnt;
                cnt++;
            }
            bottom--;
            for(int i = bottom; i >= top && cnt <= n*n; i--){
                res[i][left] = cnt;
                cnt++;
            }
            left++;
        }
        return res;
    }
};