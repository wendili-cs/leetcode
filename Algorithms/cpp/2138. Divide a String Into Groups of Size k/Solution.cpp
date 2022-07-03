// https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        for(int i = 0; i < s.length(); i += k){
            res.push_back(s.substr(i, k));
        }
        while(res.back().length() < k) res.back().push_back(fill);
        return res;
    }
};