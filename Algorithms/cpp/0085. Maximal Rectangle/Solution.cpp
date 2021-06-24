// https://leetcode-cn.com/problems/maximal-rectangle/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<int> heights(n, 0);
        function<int(vector<int>)> solve;
        solve = [&](vector<int> heights) -> int {
            int ret = 0;
            stack<int> stk;
            heights.push_back(0);
            for(int t = 0; t < heights.size(); t++){
                while(!stk.empty() && heights[stk.top()] > heights[t]){
                    int h = heights[stk.top()];
                    stk.pop();
                    ret = max(ret, stk.empty()?h*t:h*(t - 1 - stk.top()));
                }
                stk.push(t);
            }
            return ret;
        };

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1') heights[j] += 1;
                else heights[j] = 0;
            }
            res = max(solve(heights), res);
        }
        return res;
    }
};