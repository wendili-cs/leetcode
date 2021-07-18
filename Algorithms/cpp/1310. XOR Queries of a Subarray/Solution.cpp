// https://leetcode-cn.com/problems/xor-queries-of-a-subarray/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> pxor(arr.size() + 1, 0), res;
        for(int i = 1; i <= arr.size(); i++){
            pxor[i] = pxor[i - 1]^arr[i - 1];
        }
        for(auto query:queries){
            res.push_back(pxor[query[1] + 1]^pxor[query[0]]);
        }
        return res;
    }
};