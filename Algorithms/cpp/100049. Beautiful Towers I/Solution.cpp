// https://leetcode.com/contest/weekly-contest-364/problems/beautiful-towers-i/

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        long res = 0;
        for(int x = 0; x < n; x++){
            long tmp_res = 0, cur_max = maxHeights[x];
            for(int i = x; i >= 0; i--){
                cur_max = min(cur_max, (long)maxHeights[i]);
                tmp_res += cur_max;
            }
            cur_max = maxHeights[x];
            for(int i = x; i < n; i++){
                cur_max = min(cur_max, (long)maxHeights[i]);
                tmp_res += cur_max;
            }
            tmp_res -= maxHeights[x];
            res = max(tmp_res, res);
        }
        return res;
    }
};