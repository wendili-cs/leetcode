// https://leetcode.com/problems/russian-doll-envelopes/

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> res;
        res.push_back(envelopes[0][1]); 
        // the height of the first envelop (with smallest w)
        // res[i] < res[i + 1] (height)
        // and we read from smallest width to larger width
        // so if next one x has larger height, we put it to the end
        // otherwise, we find a y such that res[y] < res[x] < res[y + 1]
        // and replace res[y + 1] with res[x]
        for(int i = 1; i < n; i++){
            if(envelopes[i][1] > res.back()){
                res.push_back(envelopes[i][1]);
            }
            else{
                auto it = lower_bound(res.begin(), res.end(), envelopes[i][1]);
                *it = envelopes[i][1];
            }
        }
        return res.size();
    }
};