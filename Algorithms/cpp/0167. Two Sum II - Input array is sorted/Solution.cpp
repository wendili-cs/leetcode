// https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        int idx_1 = len - 1;
        int idx_2;
        for(idx_2 = 0; idx_2 < len; idx_2++){
            while(numbers[idx_2] + numbers[idx_1] > target){
                idx_1--;
            }
            if(numbers[idx_2] + numbers[idx_1] == target){
                break;
            }
        }
        return {idx_2 + 1, idx_1 + 1};
    }
};