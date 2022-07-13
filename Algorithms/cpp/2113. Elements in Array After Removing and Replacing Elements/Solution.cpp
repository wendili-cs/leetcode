// https://leetcode.com/problems/elements-in-array-after-removing-and-replacing-elements/

class Solution {
public:
    vector<int> elementInNums(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res(queries.size());
        int n = nums.size();
        for(int i = 0; i < queries.size(); i++){
            int t = queries[i][0]%(2*n);
            if(t < n){
                int idx = t + queries[i][1];
                res[i] = (idx < n) ? nums[idx]:-1;
            }
            else if(t > n){
                int idx = queries[i][1], len = t - n;
                res[i] = (idx < len) ? nums[idx]:-1;
            }
            else res[i] = -1;
        }
        return res;
    }
};