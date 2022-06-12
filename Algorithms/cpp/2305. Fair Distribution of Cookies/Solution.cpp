// https://leetcode.com/problems/fair-distribution-of-cookies/

class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int res = INT_MAX;
        vector<int> nums(k, 0); // assignment of each person
        function<void(int)> backtrace;
        backtrace = [&](int idx) -> void {
            if(idx == cookies.size()) {
                res = min(res, *max_element(nums.begin(), nums.end()));
                return;
            }
            for(int i = 0; i < k; i++){
                nums[i] += cookies[idx];
                backtrace(idx + 1);
                nums[i] -= cookies[idx];
            }
        };
        backtrace(0);
        return res;
    }
};