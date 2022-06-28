// https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/

class Solution {
public:
    int minimumSum(int num) {
        vector<int> nums;
        for(int i = 0; i < 4; i++){
            nums.push_back(num%10);
            num /= 10;
        }
        sort(nums.begin(), nums.end());
        return (nums[0] + nums[1])*10 + nums[2] + nums[3];
    }
};