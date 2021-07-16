// https://leetcode-cn.com/problems/range-sum-query-2d-immutable/

class NumMatrix {
private:
    vector<vector<int> > psum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        psum = matrix;
        for(int i = 0 ;i < psum.size(); i++){
            for(int j = 1; j < psum[0].size(); j++){
                psum[i][j] += psum[i][j - 1];
            }
        }

        for(int i = 1 ;i < psum.size(); i++){
            for(int j = 0; j < psum[0].size(); j++){
                psum[i][j] += psum[i - 1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return psum[row2][col2] - (row1==0?0:psum[row1 - 1][col2]) - (col1==0?0:psum[row2][col1 - 1]) + ((col1==0||row1==0)?0:psum[row1 - 1][col1 - 1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */