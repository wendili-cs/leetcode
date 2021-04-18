// https://leetcode-cn.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int> > q;
        for(const auto& num:nums){
            if(num > 0){
                q.push(num);
            }
        }
        if(q.empty()){
            return 1;
        }
        if(q.top() != 1){
            return 1;
        }
        int temp = q.top();
        while(!q.empty()){
            q.pop();
            if(q.top() == temp){ // 重复元素的可能性
                continue;
            }
            if(q.top() != temp + 1){
                return temp + 1;
            }
            temp = q.top();
        }
        return temp + 1;

    }
};