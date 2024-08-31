// https://leetcode.com/problems/best-meeting-point/

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> xpos, ypos;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    xpos.push_back(i);
                    ypos.push_back(j);
                }
            }
        }
        sort(xpos.begin(), xpos.end());
        sort(ypos.begin(), ypos.end());

        int sum = 0, p = xpos.size(), xm = xpos[p/2], ym = ypos[p/2];
        for(int i = 0; i < p; i++){
            sum += abs(xpos[i] - xm);
            sum += abs(ypos[i] - ym);
        }
        return sum;
    }
};