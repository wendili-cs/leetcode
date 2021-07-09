// https://leetcode-cn.com/problems/degree-of-an-array/

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int most_cnt = 0;
        map<int, int> cnter;
        map<int, vector<int> > indexes;
        for(int i = 0; i < nums.size(); i++){
            cnter[nums[i]]++;
            indexes[nums[i]].push_back(i);
            most_cnt = max(most_cnt, cnter[nums[i]]);
        }
        int res = INT_MAX;
        for(auto iter:cnter){
            if(iter.second == most_cnt){
                res = min(res, indexes[iter.first].back() - indexes[iter.first].front() + 1);
            }
        }
        return res;
    }
};