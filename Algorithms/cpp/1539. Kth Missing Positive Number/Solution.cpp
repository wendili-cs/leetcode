// https://leetcode-cn.com/problems/kth-missing-positive-number/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int idx = 0, cnt = 0, i;
        for(i = 1; cnt < k;i++){
            if(idx < arr.size() && arr[idx] == i) idx++;
            else cnt++;
        }
        return i - 1;
    }
};