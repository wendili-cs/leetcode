// https://leetcode-cn.com/problems/range-sum-query-immutable/

class NumArray {
private:
    vector<int> psum;
public:
    NumArray(vector<int>& nums) {
        psum = nums;
        for(int i = 1; i < nums.size(); i++) psum[i] += psum[i - 1];
    }
    
    int sumRange(int left, int right) {
        return psum[right] - (left==0?0:psum[left - 1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */