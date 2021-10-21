// https://leetcode.com/problems/range-addition/

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> arr(length, 0);
        for(auto& update:updates){
            int s = update[0], e = update[1], v = update[2];
            arr[s] += v;
            if(e != length - 1) arr[e + 1] -= v;
        }
        partial_sum(arr.begin(), arr.end(), arr.begin());
        return arr;
    }
};