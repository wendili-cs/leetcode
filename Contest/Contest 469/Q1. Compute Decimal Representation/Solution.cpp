// https://leetcode.com/contest/weekly-contest-469/problems/compute-decimal-representation/description/

class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        long x = 1;
        vector<int> res;
        while(n > 0) {
            if(n % 10 != 0) {
                res.push_back((n % 10)*x);
            }
            x *= 10;
            n /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};©leetcode