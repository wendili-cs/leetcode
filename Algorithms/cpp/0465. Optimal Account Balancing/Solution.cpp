// https://leetcode.com/problems/optimal-account-balancing/

class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> mp;
        for(auto& trans:transactions){
            mp[trans[0]] -= trans[2];
            mp[trans[1]] += trans[2];
        }
        vector<int> accounts;
        for(auto it:mp){
            if(it.second != 0) accounts.push_back(it.second);
        }
        int res = INT_MAX, n = accounts.size();
        if(n == 0) return 0;
        function<void(int, int)> dfs;
        dfs = [&](int start, int count) -> void {
            while(start < n && accounts[start] == 0) start++;
            if(start == n){
                res = min(res, count);
                return;
            }
            for(int i = start + 1; i < n; i++){
                if(accounts[start]*accounts[i] < 0){
                    accounts[i] += accounts[start];
                    dfs(start + 1, count + 1);
                    accounts[i] -= accounts[start];
                }
            }
        };
        dfs(0, 0);
        return res;
    }
};