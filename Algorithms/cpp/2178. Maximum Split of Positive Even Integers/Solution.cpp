// https://leetcode.com/problems/maximum-split-of-positive-even-integers/

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum & 1) return {};
        long long sum = 0;
        // (2 + 2*k)*k/2 = k(k + 1)
        long l = 0, r = finalSum>100000?100000:finalSum;
        while(l < r){
            long mid = l + (r - l + 1)/2;
            if(mid*(mid + 1) <= finalSum){
                l = mid;
            }
            else{
                r = mid - 1;
            }
        }
        vector<long long> res(l);
        for(int i = 0; i < l - 1; i++){
            res[i] = 2*(i + 1);
        }
        res.back() = finalSum - l*(l - 1);
        return res;
    }
};