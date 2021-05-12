// https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/

class Solution {
public:
    int findKthNumber(int n, int k) {
        auto get_nums = [&](int &prefix) -> int {
            long cur = prefix, next = prefix + 1;
            int count = 0;
            while(cur <= n){
                count += min((long)(n + 1), next) - cur;
                next *= 10;
                cur *= 10;
            }
            return count;
        };
        int prefix = 1, p = 1;
        while(p < k){
            int count = get_nums(prefix);
            if(p + count > k){
                prefix *= 10;
                p++;
            }
            else{ // p + count <= k
                prefix++;
                p += count;
            }
        }
        return prefix;
    }
};