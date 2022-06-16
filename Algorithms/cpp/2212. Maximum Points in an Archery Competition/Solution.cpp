// https://leetcode.com/problems/maximum-points-in-an-archery-competition/

class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> cur(12, 0), res;
        function<void(int, int, int)> recur;
        int max_score = 0;
        recur = [&](int idx, int remain, int score) -> void {
            if(remain < 0) return;
            if(idx == 12){
                if(max_score < score){
                    res = cur;
                    res.back() += remain; // use all the remaining arrows
                    max_score = score;
                }
                return;
            }
            recur(idx + 1, remain, score);
            cur[idx] = aliceArrows[idx] + 1;
            recur(idx + 1, remain - cur[idx], score + idx);
            cur[idx] = 0;
        };
        recur(0, numArrows, 0);
        return res;
    }
};