// https://leetcode-cn.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> uset;
        for(const auto& num:nums){    
            if(uset.count(num) == 0){
                uset.emplace(num);
            }
            else{
                auto iter = uset.find(num);
                uset.erase(iter);
            }
        }
        return *uset.begin();
    }
};