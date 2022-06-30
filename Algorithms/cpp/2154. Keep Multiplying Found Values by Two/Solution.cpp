// https://leetcode.com/problems/keep-multiplying-found-values-by-two/

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> s;
        for(int & num:nums){
            if(num%original == 0){
                s.insert(num);
            }
        }
        int cur = original;
        while(s.find(cur) != s.end()){
            cur *= 2;
        }
        return cur;
    }
};