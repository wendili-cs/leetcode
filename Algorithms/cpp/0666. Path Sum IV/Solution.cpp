// https://leetcode.com/problems/path-sum-iv/

class Solution {
public:
    int pathSum(vector<int>& nums) {
        vector<vector<int>> cnts(5, vector<int>(10, 0));
        auto pos = [](int x) -> int { // get position (starts from 0)
            return (x/10)%10-1;
        };
        auto level = [](int x) -> int { // get first number
            return x/100;
        };
        auto val = [](int x) -> int { // get last number
            return x%10;
        };
        int leaf_level = level(nums.back()), res = 0;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(cnts[level(nums[i])][pos(nums[i])] == 0){ // leaf node case
                cnts[level(nums[i])][pos(nums[i])] = 1;
            }
            cnts[level(nums[i]) - 1][pos(nums[i])/2] += cnts[level(nums[i])][pos(nums[i])]; // accumlate count numbers
            res += val(nums[i])*cnts[level(nums[i])][pos(nums[i])]; // calculate how many values are added
        }
        return res;
    }
};