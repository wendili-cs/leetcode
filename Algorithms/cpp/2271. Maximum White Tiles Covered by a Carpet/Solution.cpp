// https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        vector<int> sums(tiles.size() + 1, 0), starts(tiles.size()), ends(tiles.size());
        for(int i = 0; i < tiles.size(); i++){
            sums[i + 1] = tiles[i][1] - tiles[i][0] + 1 + sums[i];
            starts[i] = tiles[i][0];
            ends[i] = tiles[i][1];
        }
        int res = 0;
        for(int i = 0; i < tiles.size(); i++){
            auto it = lower_bound(ends.begin(), ends.end(), tiles[i][0] + carpetLen);
            int idx = it - ends.begin();
            int last_len = idx >= tiles.size()?0:max((tiles[i][0] + carpetLen) - starts[idx], 0);
            res = max(res, sums[idx] + last_len - sums[i]);
            int debug = 1;
        }
        return res;
    }
};