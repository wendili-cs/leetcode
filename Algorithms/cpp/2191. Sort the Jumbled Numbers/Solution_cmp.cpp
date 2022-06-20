// https://leetcode.com/problems/sort-the-jumbled-numbers/

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto cmp = [&](int a, int b) -> bool {
            long a2 = 0, b2 = 0, base = 1;
            while(true){
                a2 += mapping[a%10]*base;
                base *= 10;
                a /= 10;
                if(a == 0) break;
            }
            base = 1;
            while(true){
                b2 += mapping[b%10]*base;
                base *= 10;
                b /= 10;
                if(b == 0) break;
            }
            return a2 < b2;
        };
        sort(nums.begin(), nums.end(), cmp);
        return nums;
    }
};