// https://leetcode.com/problems/remove-all-ones-with-row-and-column-flips/

class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            if(grid[i][0]){
                for(int j = 0; j < n; j++){
                    grid[i][j] ^= 1;
                }
            }
        }
        for(int j = 0; j < n; j++){
            int a = grid[0][j];
            for(int i = 0; i < m; i++){
                if(grid[i][j] != a) return false;
            }
        }
        return true;
    }
};