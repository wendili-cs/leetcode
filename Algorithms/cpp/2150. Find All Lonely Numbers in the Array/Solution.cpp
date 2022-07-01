// https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int& num:nums) mp[num]++;
        vector<int> res;
        for(auto it:mp){
            if(!mp.count(it.first - 1) && !mp.count(it.first + 1) && it.second == 1){
                res.push_back(it.first);
            }
        }
        return res;
    }
};