// https://leetcode-cn.com/problems/binary-search/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        auto binarySearch = [&]() -> int {
            int l = 0, r = len - 1;
            int k = l + (r - l)/2;
            while(l <= r){
                if(nums[k]==target){
                    return k;
                }
                else if(nums[k] < target){
                    l = k + 1;
                }
                else{
                    r = k - 1;
                }
                k = l + (r - l)/2;
            }
            return -1;
        };

        return binarySearch();
    }
};