// https://leetcode.com/problems/count-positions-on-street-with-required-brightness/

class Solution {
public:
    int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) {
        vector<int> way(n, 0);
        for(int i = 0; i < lights.size(); i++){
            int left = max(lights[i][0] - lights[i][1], 0);
            way[left]++;
            int right = lights[i][0] + lights[i][1] + 1;
            if(right < n) way[right]--;
        }
        int cur = 0, res = 0;
        for(int i = 0; i < n; i++){
            cur += way[i];
            if(cur >= requirement[i]) res++;
        }
        return res;
    }
};