// https://leetcode-cn.com/problems/decode-xored-array/

// 要点：异或的自反律（a^b^a=b）
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res = {first};
        for(auto num:encoded){
            first = num^first;
            res.push_back(first);
        }
        return res;
    }
};