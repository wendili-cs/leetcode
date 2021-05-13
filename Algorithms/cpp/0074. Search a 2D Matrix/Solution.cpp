// https://leetcode-cn.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), x = 0, y = n - 1;
        while(x < m && y >= 0){
            if(matrix[x][y] == target) return true;
            else if(matrix[x][y] < target) x++;
            else y--;
        }
        return false;
    }
};