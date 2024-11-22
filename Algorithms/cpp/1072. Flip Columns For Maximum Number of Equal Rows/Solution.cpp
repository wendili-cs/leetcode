// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        map<vector<int>, int> mp;
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 1){
                for(int j = 0; j < n; j++){
                    matrix[i][j] = 1 - matrix[i][j];
                }
            }
            mp[matrix[i]]++;
        }
        int res = 0;
        for(auto it:mp){
            res = max(it.second, res);
        }
        return res;
    }
};