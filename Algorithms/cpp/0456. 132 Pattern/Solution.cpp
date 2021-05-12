// https://leetcode-cn.com/problems/132-pattern/
// 单调栈（先大后小），two是最后弹出的（肯定比栈里面的小，是“2”）
// 对于每个新来的书，如果比“2”小，就是“1”，“3”在栈里面

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        if(len < 3) return false;
        stack<int> stk;
        int two = INT_MIN;
        for(int i = len - 1; i >= 0; i--){
            if(nums[i] < two) return true;
            while(!stk.empty() && nums[i] > stk.top()){
                two = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};