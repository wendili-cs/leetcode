// https://leetcode-cn.com/problems/subarray-sum-equals-k/

// 使用map记录出现同样的和的次数, 对每个i计算累计和sum并判断map内是否有sum-k
// 其实计算的是sum(num[:i]) - sum(num[:j]) == k有几个
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap; // umap[a]记录和为a出现的次数
        umap[0] = 1;
        int sum = 0, res = 0;
        for(const auto& num:nums){
            sum += num;
            if(umap[sum - k] != 0){
                res += umap[sum - k];
            }
            umap[sum] += 1;
        }
        return res;
    }
};