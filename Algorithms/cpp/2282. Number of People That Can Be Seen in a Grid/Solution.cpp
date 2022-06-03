// https://leetcode.com/problems/number-of-people-that-can-be-seen-in-a-grid/

class Solution {
public:
    vector<vector<int>> seePeople(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for(int i = m - 1; i >= 0; i--){
            vector<int> stack;
            for(int j = n - 1; j >= 0; j--){
                auto it = lower_bound(stack.rbegin(), stack.rend(), heights[i][j]);
                res[i][j] += (it - stack.rbegin()) + (it==stack.rend()?0:1);
                
                while(!stack.empty() && heights[i][j] >= stack.back()){
                    stack.pop_back();
                }
                stack.push_back(heights[i][j]);
            }
        }
        int x = 1;
        for(int j = n - 1; j >= 0; j--){
            vector<int> stack;
            for(int i = m - 1; i >= 0; i--){
                auto it = lower_bound(stack.rbegin(), stack.rend(), heights[i][j]);
                res[i][j] += (it - stack.rbegin()) + (it==stack.rend()?0:1);
                
                while(!stack.empty() && heights[i][j] >= stack.back()){
                    stack.pop_back();
                }
                stack.push_back(heights[i][j]);
            }
        }
        return res;
    }
};