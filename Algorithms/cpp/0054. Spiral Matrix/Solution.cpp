// https://leetcode-cn.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1;
        int num_elem = (right + 1) * (bottom + 1);
        vector<int> res;
        while(num_elem >= 1){
            for(int i = left; i <= right && num_elem >= 1; i++){
                res.push_back(matrix[top][i]);
                num_elem--;
            }
            top++;
            for(int i = top; i <= bottom && num_elem >= 1; i++){
                res.push_back(matrix[i][right]);
                num_elem--;
            }
            right--;
            for(int i = right; i >= left && num_elem >= 1; i--){
                res.push_back(matrix[bottom][i]);
                num_elem--;
            }
            bottom--;
            for(int i = bottom; i >= top && num_elem >= 1; i--){
                res.push_back(matrix[i][left]);
                num_elem--;
            }
            left++;
        }
        return res;
    }
};