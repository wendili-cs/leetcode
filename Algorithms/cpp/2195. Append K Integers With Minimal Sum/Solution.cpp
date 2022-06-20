// https://leetcode.com/problems/append-k-integers-with-minimal-sum/

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long res = 0, remain = k, fin;
        for(int i = 0; i < nums.size(); i++){
            if(remain > 0 && (i == 0 || nums[i] != nums[i-1])){
                long long diff = nums[i] - (i==0?0:nums[i-1]) - 1;
                diff = diff > remain ? remain:diff;
                remain -= diff;
                cout << (i==0?1:nums[i-1] + 1) << " " << (i==0?1:nums[i-1] + 1) + diff - 1 << " " << diff << endl;
                res += (2*(i==0?1:nums[i-1] + 1) + diff - 1)*diff/2;
                // res += nums[i];
            }
        }
        if(remain > 0){
            res += (remain + 2*nums.back() + 1)*remain/2;
        }
        return res;
    }
};