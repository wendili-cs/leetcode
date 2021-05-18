// https://leetcode-cn.com/problems/russian-doll-envelopes/

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]) return a[1] > b[1];
        else return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty()) return 0;
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> res;
        res.push_back(envelopes[0][1]);
        for(int i = 0; i < envelopes.size(); i++){
            if(envelopes[i][1] > res.back()){
                res.push_back(envelopes[i][1]);
            }
            else{
                auto iter = lower_bound(res.begin(), res.end(), envelopes[i][1]);
                *iter = envelopes[i][1];
            }
        }
        return res.size();
    }
};