// https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> tria;
        tria.push_back({1}); // level 1
        for(int l = 1; l < numRows; l++){
            vector<int> row;
            for(int i = 0; i <= l; i++){
                int p1 = i - 1 >= 0 ? tria[l - 1][i - 1] : 0;
                int p2 = i <= l - 1 ? tria[l - 1][i] : 0;
                row.push_back(p1 + p2);
            }
            tria.push_back(row);
        }
        return tria;
    }
};