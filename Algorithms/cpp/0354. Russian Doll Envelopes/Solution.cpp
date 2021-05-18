// https://leetcode-cn.com/problems/russian-doll-envelopes/
// 思路：第一维度从小到大，相等的情况下，第二维度从大到小，可以转换成300. Longest Increasing Subsequence一题。维护一个res，res[i]表示长度为i的升序数列的末尾的最小值
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