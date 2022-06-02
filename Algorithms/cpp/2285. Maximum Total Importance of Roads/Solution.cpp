// https://leetcode.com/problems/maximum-total-importance-of-roads/

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> cnt(n, 0);
        for(auto &road:roads){
            cnt[road[0]]++;
            cnt[road[1]]++;
        }
        sort(cnt.begin(), cnt.end());
        long long res = 0;
        for(int i = 0; i < n; i++){
            res += (long)cnt[i]*(long)(i + 1);
        }
        return res;
    }
};