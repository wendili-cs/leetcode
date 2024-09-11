// https://leetcode.com/problems/number-of-excellent-pairs/

class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> s; // we only count each number once
        vector<int> bit_cnt(32, 0); //  bit_cnt[x] means how many numbers in the nums has x bits
        for(int &num:nums){
            if(s.find(num) != s.end()) continue;
            int cnt = 0;
            for(int i = 0; i < 32; i++){
                if(num & (1 << i)) cnt++;
            }
            bit_cnt[cnt]++;
            s.insert(num);
        }
        long res = 0;
        for(int i = 0; i < 32; i++){
            for(int j = i; j < 32; j++){
                if(i + j >= k){
                    if(i == j){
                        res += bit_cnt[i]*bit_cnt[j];
                    }
                    else{
                        res += 2*bit_cnt[i]*bit_cnt[j];
                    }
                }
            }
        }
        return res;
    }
};