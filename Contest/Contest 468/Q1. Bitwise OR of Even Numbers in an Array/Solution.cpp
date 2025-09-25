class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 2 == 0) {
                res |= nums[i];
            }
        }
        return res;
    }
};=