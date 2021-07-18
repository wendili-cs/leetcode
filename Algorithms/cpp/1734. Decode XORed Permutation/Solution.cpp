// https://leetcode-cn.com/problems/decode-xored-permutation/

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int a = 0;
        for(int i = 1; i <= encoded.size() + 1; i++) a ^= i;
        for(int i = 1; i < encoded.size(); i += 2) a ^= encoded[i];
        vector<int> res(encoded.size() + 1);
        res[0] = a;
        for(int i = 0; i < encoded.size(); i++) res[i + 1] = res[i]^encoded[i];
        return res;
    }
};