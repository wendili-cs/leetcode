// https://leetcode-cn.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool row_flag = false, col_flag = false;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    if(i == 0) row_flag = true;
                    if(j == 0) col_flag = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(row_flag){
            for(int j = 0; j < n; j++) matrix[0][j] = 0;
        }
        if(col_flag){
            for(int i = 0; i < m; i++) matrix[i][0] = 0;
        }
    }
};