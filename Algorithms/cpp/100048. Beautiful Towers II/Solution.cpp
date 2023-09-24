// https://leetcode.com/contest/weekly-contest-364/problems/beautiful-towers-ii/

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<long> left(n), right(n);
        stack<pair<long,int>> stk;
        
        stk.push({maxHeights[0], 0}); // from large to small
        left[0] = maxHeights[0];
        for(int i = 1; i < n; i++){
            if(stk.top().first < maxHeights[i]){
                left[i] = left[i - 1] + maxHeights[i];
                stk.push({maxHeights[i], i});
            }
            else{
                while(!stk.empty() && stk.top().first > maxHeights[i]) stk.pop();
                int pre_idx = stk.empty()? -1:stk.top().second;
                left[i] = (pre_idx==-1?0:left[pre_idx]) + (i - pre_idx)*(long)maxHeights[i];
                stk.push({maxHeights[i], i});
            }
        }
        
        while(!stk.empty()) stk.pop();
        stk.push({maxHeights[n - 1], n - 1});
        right[n - 1] = maxHeights[n - 1];
        for(int i = n - 2; i >= 0; i--){
            if(stk.top().first < maxHeights[i]){
                right[i] = right[i + 1] + maxHeights[i];
                stk.push({maxHeights[i], i});
            }
            else{
                while(!stk.empty() && stk.top().first > maxHeights[i]) stk.pop();
                int pre_idx = stk.empty()? n:stk.top().second; // note here pre_idx > i
                right[i] = (pre_idx==n?0:right[pre_idx]) + (pre_idx - i)*(long)maxHeights[i];
                stk.push({maxHeights[i], i});
            }
        }
        
        long res = 0, cur;
        for(int x = 0; x < n; x++){
            cur = left[x] + right[x] - maxHeights[x];
            res = max(cur, res);
        }
        return res;
    }
};