// https://leetcode.com/problems/create-grid-with-exactly-k-paths-i/

class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {
        auto constructGrid = [&](int X, int Y){
            // construct a vector<string> result
            // X and Y are the small grid pattern
            // After small grid is constructed: starting from (X-1, Y-1), to right, then down
            vector<string> res(m, string(n, '#'));
            for(int x = 0; x < X; x++){
                for(int y = 0; y < Y; y++){
                    res[x][y] = '.';
                }
            }
            if(X == 3 && Y == 3){
                // special case for 3x3 case (k=4): 
                // a 3 x 3 block with the top-right and bottom-left cells blocked.
                res[0][Y-1] = '#';
                res[X - 1][0] = '#';
            }
            for(int x = X - 1; x < m; x++){
                res[x][Y - 1] = '.';
            }
            for(int y = Y - 1; y < n; y++){
                res[m - 1][y] = '.';
            }
            return res;
        };

        // k = 1, always has a solution
        if(k == 1){
            return constructGrid(1, 1);
        }
        // k = 2, need a 2x2 small grid pattern
        if(k == 2 && m >= 2 && n >= 2){
            return constructGrid(2, 2);
        }
        // k = 3, need a 2x3 or 3x2 pattern
        else if(k == 3 && (m >= 3 && n >= 2)){
            return constructGrid(3, 2);
        }
        else if(k == 3 && (m >= 2 && n >= 3)){
            return constructGrid(2, 3);
        }
        // k = 4, need a 2x4, 4x2, or 3x3 pattern
        else if(k == 4 && (m >= 4 && n >= 2)){
            return constructGrid(4, 2);
        }
        else if(k == 4 && (m >= 2 && n >= 4)){
            return constructGrid(2, 4);
        }
        else if(k == 4 && (m >= 3 && n >= 3)){
            return constructGrid(3, 3);
        }
        return {};
    }
};