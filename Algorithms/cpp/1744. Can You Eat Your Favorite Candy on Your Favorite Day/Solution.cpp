// https://leetcode-cn.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        vector<long>psum(candiesCount.size());
        for(int i = 0; i < candiesCount.size(); i++) psum[i] = (i>0?psum[i - 1]:0) + candiesCount[i];
        vector<bool> res;
        for(auto query:queries){
            long pre_num = query[0]==0?0:psum[query[0] - 1];
            long post_num = psum[query[0]];
            long least = query[1], most = (long)(query[1] + 1)*query[2];
            if(least >= post_num || most <= pre_num) res.push_back(false);
            else res.push_back(true);
        }
        return res;
    }
};