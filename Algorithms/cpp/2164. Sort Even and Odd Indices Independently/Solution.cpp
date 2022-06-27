// https://leetcode.com/problems/sort-even-and-odd-indices-independently/

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odds, evens, res;
        for(int i = 0; i < nums.size(); i++){
            if(i & 1) odds.push_back(nums[i]);
            else evens.push_back(nums[i]);
        }
        sort(evens.begin(), evens.end());
        sort(odds.begin(), odds.end(), [](int &a, int &b){return a > b;});
        for(int i = 0; i < (nums.size() + 1)/2; i++){
            res.push_back(evens[i]);
            if(i < odds.size()) res.push_back(odds[i]);
        }
        return res;
    }
};