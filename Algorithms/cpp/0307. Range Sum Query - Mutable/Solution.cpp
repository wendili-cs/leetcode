// https://leetcode.com/problems/range-sum-query-mutable/

class NumArray {
private:
    vector<int> tree;
    vector<int> arr;
public:
    NumArray(vector<int>& nums) {
        tree = vector<int>(nums.size() + 1, 0);
        arr = vector<int>(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++){
            update(i, nums[i]);
        }
    }
    
    int lowbit(int x){
        return x &(-x);
    }

    void update(int index, int val) {
        int diff = val - arr[index];
        if(diff == 0) return;
        arr[index] = val;
        index++; // BIT starts with index 1
        while(index <= arr.size()){
            tree[index] += diff;
            index += lowbit(index);
        }
    }
    
    int query(int index) {
        if(index < 0) return 0;
        index++;
        int ret = 0;
        while(index > 0){
            ret += tree[index];
            index -= lowbit(index);
        }
        return ret;
    }

    int sumRange(int left, int right) {
        return query(right) - query(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */