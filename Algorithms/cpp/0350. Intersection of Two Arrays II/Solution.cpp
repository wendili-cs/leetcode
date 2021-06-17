// https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        for(const int& num:nums1){
            umap[num]++;
        }
        vector<int> res;
        for(const int&num:nums2){
            if(umap[num] > 0){
                umap[num]--;
                res.push_back(num);
            }
        }
        return res;
    }
};