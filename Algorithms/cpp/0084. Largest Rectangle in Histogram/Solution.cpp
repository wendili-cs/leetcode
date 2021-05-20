// https://leetcode-cn.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        int max_rect = 0;
        stack<int> stk;
        // 对栈中柱体来说，栈中的下一个柱体就是其「左边第一个小于自身的柱体」；
        // 若当前柱体 i 的高度小于栈顶柱体的高度，说明 i 是栈顶柱体的「右边第一个小于栈顶柱体的柱体」。
        // 因此以栈顶柱体为高的矩形的左右宽度边界就确定了，可以计算面积
        for(int i = 0; i < heights.size(); i++){
            while(!stk.empty() && heights[stk.top()] > heights[i]){
                int h = heights[stk.top()];
                stk.pop();
                max_rect = max(max_rect, h*(i - stk.top() - 1));
                
            }
            stk.push(i);
        }
        return max_rect;
    }
};