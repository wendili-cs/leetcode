// https://leetcode-cn.com/problems/summary-ranges/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int idx = 0, len = nums.size();
        if(len==1){
            res.push_back(to_string(nums[0]));
        }
        if(len==0||len==1){
            return res;
        }
        
        for(int i = 1; i < len; i++){
            if(nums[i] != nums[i-1] + 1){
                if(idx < i-1){
                    res.push_back(to_string(nums[idx]) + "->" + to_string(nums[i-1]));
                }
                else{
                    res.push_back(to_string(nums[idx]));
                }
                idx = i;
            }
        }
        if(idx==len-1){
            res.push_back(to_string(nums[idx]));
        }
        else{
            res.push_back(to_string(nums[idx]) + "->" + to_string(nums[len-1]));
        }
        return res;
    }
};