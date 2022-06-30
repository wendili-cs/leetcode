// https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int> sums(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++){
            sums[i + 1] = nums[i] + sums[i];
        }
        map<int, vector<int>> mp;
        for(int i = 0; i < sums.size(); i++){
            int left_score = i - sums[i];
            int right_score = sums.back() - sums[i];
            mp[left_score + right_score].push_back(i);
        }
        return mp.rbegin()->second;
    }
};