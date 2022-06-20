// https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        map<int,int> mp;
        int max_cnt = 0, max_one;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i - 1] == key){
                mp[nums[i]]++;
                if(mp[nums[i]] > max_cnt){
                    max_cnt = mp[nums[i]];
                    max_one = nums[i];
                }
            }
        }
        return max_one;
    }
};