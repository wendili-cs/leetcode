// https://leetcode-cn.com/problems/spiral-matrix/
// https://leetcode.com/problems/spiral-matrix/description/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1;
        int nums = matrix.size()*matrix[0].size(); // 还剩下多少个元素要遍历
        vector<int> res;
        while(nums > 0){
            for(int j = left; j <= right && nums > 0; j++){ 
                // 右走j++，此时一定在matrix[top][j]
                res.push_back(matrix[top][j]);
                nums--;
            }
            top++; // 走完top这一行
            for(int i = top; i <= bottom && nums > 0; i++){
                // 下走i++，此时一定在matrix[i][right]
                res.push_back(matrix[i][right]);
                nums--;
            }
            right--; // 走完right这一列
            for(int j = right; j >= left && nums > 0; j--){
                res.push_back(matrix[bottom][j]);
                nums--;
            }
            bottom--; // 走完bottom这一行
            for(int i = bottom; i >= top && nums > 0; i--){
                res.push_back(matrix[i][left]);
                nums--;
            }
            left++; // 走完left这一列
        }
        return res;
    }
};