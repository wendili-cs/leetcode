// https://leetcode-cn.com/problems/delete-and-earn/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> cnter;
        priority_queue<int> pq;
        for(auto& num:nums){
            if(cnter.find(num) == cnter.end()) pq.emplace(num);
            cnter[num]++;
        }
        vector<int> dp(pq.size() + 1, 0);
        dp[0] = 0;
        for(int i = 1; !pq.empty(); i++){
            int num = pq.top();
            pq.pop();
            if(i != 1 && cnter.find(num + 1) != cnter.end()) dp[i] = max(dp[i - 1], dp[i - 2] + num*cnter[num]);
            else dp[i] = dp[i - 1] + num*cnter[num];
        }
        return dp.back();
    }
};