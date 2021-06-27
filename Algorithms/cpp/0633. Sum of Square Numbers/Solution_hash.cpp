// https://leetcode-cn.com/problems/sum-of-square-numbers/

class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_map<int, int> umap;
        for(long i = 0; i*i <= c; i++){
            if(umap.find(i*i) != umap.end() || i*i*2 == c) return true;
            else umap[c - i*i] = i;
        }
        return false;
    }
};