// https://leetcode-cn.com/problems/next-greater-element-ii/

// 要点：维护一个已经排序好的单调降序栈，对于新的元素若小于栈顶则放入栈，大于栈顶则弹出到栈顶元素大于当前元素为止，同时可以更新当前元素的next greater element
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        int len = nums.size();
        vector<int> res(len, -1);
        for(int i = 0; i < len*2; i++){
            int num = nums[i%len];
            while(!stk.empty() && nums[stk.top()] < num){
                res[stk.top()] = num;
                stk.pop();
            }
            if(i < len) stk.push(i%len); // 最多可能叠2次（完全降序）
        }
        return res;
    }
};