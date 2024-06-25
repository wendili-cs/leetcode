// https://leetcode.com/problems/3sum-smaller/

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            int j = i + 1, k = nums.size() - 1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] < target){
                    res += k - j;
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return res;
    }
};