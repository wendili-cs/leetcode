// https://leetcode.com/problems/minimum-cost-to-reach-city-with-discounts/

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        // dp[x][y] means the minimum distance from 0 to x, with y discounts remaining
        vector<vector<int>> dp(n, vector<int>(discounts + 1, INT_MAX)), g(n, vector<int>(n, -1));
        vector<vector<int>> adj(n);
        set<vector<int>> s; // {cost, to, discounts}
        // sort(highways.begin(), highways.end(), [](vector<int>&a, vector<int>&b) {return a[2] > b[2];});
        for(auto& h:highways){
            g[h[0]][h[1]] = h[2];
            g[h[1]][h[0]] = h[2];
            adj[h[0]].push_back(h[1]);
            adj[h[1]].push_back(h[0]);
        }
        s.insert({0, 0, discounts});
        while(!s.empty()){
            int cost = (*s.begin())[0], node = (*s.begin())[1], dcnt = (*s.begin())[2];
            s.erase(s.begin());
            if(node == n - 1)
                return cost;
            for(int next:adj[node]){
                int dis = g[node][next];
                if(dp[next][dcnt] > dis + cost){
                    dp[next][dcnt] = dis + cost;
                    s.insert({dp[next][dcnt], next, dcnt});
                }
                if(dcnt > 0 && dp[next][dcnt - 1] > dis/2 + cost){
                    dp[next][dcnt - 1] = dis/2 + cost;
                    s.insert({dp[next][dcnt - 1], next, dcnt - 1});
                }
            }
        }
        return -1;
    }
};