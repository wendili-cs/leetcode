// https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            unordered_set<int> s, s2;
            for(int j = 0; j < n; j++){
                s.insert(matrix[i][j]);
                s2.insert(matrix[j][i]);
            }
            if(s.size() != n || s2.size() != n) return false;
        }
        return true;
    }
};