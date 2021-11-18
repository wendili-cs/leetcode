// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/

class Solution {
public:
    int minSwaps(vector<int>& data) {
        int min_swap = data.size(), cnter = 0, ones = accumulate(data.begin(), data.end(), 0), r = 0;
        while(r < data.size()){
            cnter += data[r];
            if(r - ones >= 0) cnter -= data[r - ones];
            if(r >= ones - 1) min_swap = min(min_swap, ones - cnter);
            r++;
        }
        return min_swap;
    }
};