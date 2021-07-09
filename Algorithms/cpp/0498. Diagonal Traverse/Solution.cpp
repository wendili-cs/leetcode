// https://leetcode-cn.com/problems/diagonal-traverse/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;
        for(int i = 0; i <= m + n - 2; i++){
            for(int j = 0; j <= i; j++){ // mat[j][i - j] when i&1, else mat[i - j][j]
                if((i&1) && j < m && (i - j) < n) res.push_back(mat[j][i - j]);
                else if(!(i&1) && (i - j) < m && j < n) res.push_back(mat[i - j][j]);
            }
        }
        return res;
    }
};