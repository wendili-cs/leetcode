// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int cur = 0, res = 0, len = cardPoints.size();
        for(int i = 0; i < k; i++) cur += cardPoints[i];
        res = cur;
        for(int i = 0; i < k; i++){
            cur = cur - cardPoints[k - 1 - i] + cardPoints[len - i - 1];
            res = max(cur, res);
        }
        return res;
    }
};