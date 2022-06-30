// https://leetcode.com/problems/minimum-number-of-lines-to-cover-points/

class Solution {
public:
    int minimumLines(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        auto is_line = [&](int i, int j, int k) -> bool {
            if(dp[i][j][k] == -1){
                double a1 = (points[j][0]==points[i][0])? DBL_MAX:((double)points[j][1] - points[i][1])/(points[j][0] - points[i][0]);
                double a2 = (points[j][0]==points[k][0])? DBL_MAX:((double)points[j][1] - points[k][1])/(points[j][0] - points[k][0]);
                // cout << a1 << " " << a2 << endl;
                dp[i][j][k] = (a2 == a1);
            }
            return dp[i][j][k];
        };
        vector<vector<int>> lines;
        int p = 0;
        function<int(int, int)> recur;
        recur = [&](int p, int r) -> int { // r -> count points, p -> each bit represent a point
            for(int i = 0; i < n; i++){ // remove all lined points
                if(p & (1 << i)) continue;
                for(int j = 0; j < lines.size(); j++){
                    if(is_line(lines[j][0], lines[j][1], i)){
                        p |= (1 << i);
                        r--;
                        break;
                    }
                }
            }
            if(r == 0) return 0;
            else if(r <= 2) return 1;
            int ret = 100;
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    if(!(p & (1 << i)) && !(p & (1 << j))){
                        int new_p = p | (1 << i) | (1 << j);
                        lines.push_back({i, j});
                        ret = min(ret, 1 + recur(new_p, r - 2));
                        lines.pop_back();
                    }
                }
            }
            return ret;
        };
        int res = recur(0, n);
        return res;
    }
};