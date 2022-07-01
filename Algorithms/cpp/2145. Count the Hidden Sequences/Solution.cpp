// https://leetcode.com/problems/count-the-hidden-sequences/

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long cur = 0, nmax = 0, nmin = 0;
        for(int i = 0; i < differences.size(); i++){
            cur += differences[i];
            nmax = nmax > cur ? nmax:cur;
            nmin = nmin < cur ? nmin:cur;
        }
        long res = (upper - lower + 1) - (nmax - nmin);
        return res > 0 ? res:0;
    }
};