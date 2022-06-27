// https://leetcode.com/problems/removing-minimum-number-of-magic-beans/

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        long res = 10000000000, sum = 0;
        for(int i = 0; i < beans.size(); i++) sum += beans[i];
        for(int i = 0; i < beans.size(); i++){
            long num_remove = sum - (beans.size() - i)*beans[i];
            res = res > num_remove? num_remove:res;
        }
        return res;
    }
};