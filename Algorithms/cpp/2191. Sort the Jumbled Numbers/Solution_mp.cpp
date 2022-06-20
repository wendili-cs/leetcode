// https://leetcode.com/problems/sort-the-jumbled-numbers/submissions/

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto trans = [&](int a) -> int {
            int a2 = 0, base = 1;
            while(true){
                a2 += mapping[a%10]*base;
                base *= 10;
                a /= 10;
                if(a == 0) break;
            }
            return a2;
        };
        map<int, vector<int>> mp;
        for(int& num:nums){
            mp[trans(num)].push_back(num);
        }
        vector<int> res;
        for(auto it:mp){
            for(int num:it.second){
                res.push_back(num);
            }
        }
        return res;
    }
};