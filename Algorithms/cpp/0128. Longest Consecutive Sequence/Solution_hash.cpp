class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_len = 0;
        unordered_map<int, int> umap;
        for(int& num:nums){
            auto iter = umap.find(num);
            if(iter == umap.end()){
                auto iter_l = umap.find(num - 1);
                int left = iter_l == umap.end()? 0:iter_l->second;
                auto iter_r = umap.find(num + 1);
                int right = iter_r == umap.end()? 0:iter_r->second;

                int len = left + right + 1;
                max_len = max(max_len, len);

                umap[num] = len;
                umap[num - left] = len;
                umap[num + right] = len;
            }
        }
        return max_len;
    }
};