// https://leetcode.com/problems/the-kth-factor-of-n/

class Solution {
public:
    int kthFactor(int n, int k) {
        if(k == 1) return 1;
        int cnt = 1;
        for(int i = 2; i <= n; i++){
            if(n%i == 0){
                cnt++;
                if(cnt == k) return i;
            }
        }
        return -1;
    }
};