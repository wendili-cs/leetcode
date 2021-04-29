// https://leetcode-cn.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res(1, vector<int>(1, 1));
        for(int i = 1; i < numRows; i++){
            vector<int> temp = {1};
            vector<int> last = res.back();
            for(int j = 0; j < last.size() - 1; j++){
                temp.push_back(last[j] + last[j + 1]);
            }
            temp.push_back(1);
            res.push_back(temp);
        }
        return res;
    }
};