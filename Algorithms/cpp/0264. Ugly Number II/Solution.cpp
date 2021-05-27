// https://leetcode-cn.com/problems/ugly-number-ii/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>ugly(n, 1), idx(3, 0), nums = {2, 3, 5};
        for(int i = 1; i < n; i++){
            vector<int> temp(3);
            for(int i = 0; i < 3; i++) temp[i] = ugly[idx[i]]*nums[i];
            int min_v = *min_element(temp.begin(), temp.end());
            for(int i = 0; i < 3; i++)
                if(min_v == temp[i]) idx[i]++;
            ugly[i] = min_v;
        }
        return ugly.back();
    }
};