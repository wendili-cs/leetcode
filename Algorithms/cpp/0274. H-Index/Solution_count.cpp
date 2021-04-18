// https://leetcode-cn.com/problems/h-index
// 做法：如果一篇文章的引用次数超过论文的总数 nn，那么将它的引用次数降低为 nn 也不会改变 hh 指数的值。

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        vector<int> counts(len + 1, 0);
        for(const auto& cite:citations){
            counts[min(len, cite)]++;
        }
        int k = len;
        for(int sum = counts[k]; sum < k; sum += counts[k]){
            k--;
        }
        return k;
    }
};