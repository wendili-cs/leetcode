// https://leetcode.com/problems/finding-3-digit-even-numbers/

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> s;
        int n = digits.size();
        for(int i = 0; i < n; i++){
            if(digits[i] == 0) continue;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                for(int k = 0; k < n; k++){
                    if(i == k || j == k || digits[k]%2 != 0) continue;
                    s.insert(digits[i]*100 + digits[j]*10 + digits[k]);
                }
            }
        }
        vector<int> res(s.begin(), s.end());
        return res;
    }
};