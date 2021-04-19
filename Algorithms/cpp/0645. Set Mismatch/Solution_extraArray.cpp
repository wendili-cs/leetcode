// https://leetcode-cn.com/problems/set-mismatch/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int len = nums.size();
        vector<int> count(len + 1, 0);
        for(int i = 0; i < len; i++){
            count[nums[i]] += 1;
        }
        int duplicate, missing;
        for(int i = 1; i < len + 1; i++){
            if(count[i] == 0){
                missing = i;
            }
            else if(count[i] == 2){
                duplicate = i;
            }
        }
        return {duplicate, missing};
    }
};