// https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if(a.empty()) return {};
        int len = a.size();
        vector<int> left(len), right(len), res(len);
        left[0] = 1;
        right[len - 1] = 1;
        for(int i = 1; i < len; i++) left[i] = left[i - 1]*a[i - 1];
        for(int i = len - 2; i >= 0; i--) right[i] = right[i + 1]*a[i + 1];
        for(int i = 0; i < len; i++) res[i] = left[i]*right[i];
        return res;
    }
};