// https://leetcode.com/problems/count-hills-and-valleys-in-an-array/

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        auto get_lr = [&](int idx) -> pair<int, int>{ // return [left, right]
            int l = idx, r = idx;
            while(l - 1 >=0 && nums[l - 1] == nums[idx]) l--;
            while(r + 1 < nums.size() && nums[r + 1] == nums[idx]) r++;
            return make_pair(l, r);
        };
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            auto lr = get_lr(i);
            int l = lr.first, r = lr.second;
            if(l > 0 && r < nums.size() - 1 && (nums[l - 1] - nums[l])*(nums[r + 1] - nums[r]) > 0) res++;
            i = r;
        }
        return res;
    }
};