// https://leetcode-cn.com/problems/diagonal-traverse/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;
        for(int i = 0; i < m + n - 1; i++){
            vector<int> temp;
            for(int j = max(0,i-n+1); j < min(m,i+1); j++){ // mat[j][i - j] when i&1, else mat[i - j][j]
                temp.push_back(mat[j][i - j]);
            }
            if(i % 2 == 0) reverse(temp.begin(), temp.end());
            res.insert(res.end(), temp.begin(), temp.end());
        }
        return res;
    }
};