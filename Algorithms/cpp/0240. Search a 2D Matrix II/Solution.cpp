// https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
// 选一个点idx从右上（左下同理）游走，
// 1. 和target相等返回true；
// 2. 如果比target大则左走，如果比target小则下走
// 3. 如果走完了仍然没有找到，返回false

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;
        while(x < m && y >= 0){
            if(matrix[x][y] == target) return true;
            else if(matrix[x][y] < target) x++;
            else y--;
        }
        return false;
    }
};