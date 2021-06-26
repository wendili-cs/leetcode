// https://leetcode-cn.com/problems/brick-wall/

// 对每个缝隙计数，{缝隙index:这里是砖边界的个数}
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int layer_num = wall.size();
        unordered_map<int, int> umap;
        for(auto &layer:wall){
            int r = 0;
            for(int i = 0; i < layer.size() - 1; i++){
                r += layer[i];
                umap[r]++;
            }
        }
        int res = 0, index = -1;
        for(auto iter:umap){
            res = max(res, iter.second);
        }
        return layer_num - res;
    }
};