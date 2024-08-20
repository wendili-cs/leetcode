// https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string, int> mp;
        for(string &num:nums) mp[num]++;
        int res = 0;
        for(string &num:nums){
            if(num.length() < target.length() && target.substr(0, num.length()) == num){
                string remain = target.substr(num.length());
                mp[num]--;
                res += mp[remain];
                mp[num]++;
            }
        }
        return res;
    }
};