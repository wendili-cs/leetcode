// https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        vector<int> counts(len + 1, 0);
        for(int i = 0; i < len; i++){
            counts[nums[i]]++;
        }
        for(int i = 1; i < len + 1; i++){
            if(counts[i] > 1){
                res.push_back(i);
            }
        }
        return res;
    }
};