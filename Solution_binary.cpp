// https://leetcode.com/problems/3sum-smaller/

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                int l = j + 1, r = nums.size() - 1, mid;
                while(l <= r){
                    mid = (l + r)/2;
                    if(nums[mid] + nums[i] + nums[j] < target){
                        l = mid + 1;
                    }
                    else{
                        r = mid - 1;
                    }
                }
                res += r - j;
            }
        }
        return res;
    }
};