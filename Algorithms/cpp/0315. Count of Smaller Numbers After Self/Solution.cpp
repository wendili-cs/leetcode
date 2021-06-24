// https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/

class BIT{
private:
    vector<int> tree;
    int n;
public:
    BIT(int _n): n(_n), tree(_n + 1, 0){}

    static int lower_bit(int x) {return x&(-x);}

    int query(int x){
        int ret = 0;
        while(x){
            ret += tree[x];
            x -= lower_bit(x);
        }
        return ret;
    }

    void update(int x){
        while(x <= n){
            tree[x]++;
            x += lower_bit(x);
        }
    }
};

class Solution {
public:
    vector<int> get_rank(vector<int> nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        for(int i = 0; i < nums.size(); i++){
            nums[i] = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin() + 1;
        }
        return nums;
    }
    vector<int> countSmaller(vector<int>& nums) {
        nums = get_rank(nums);
        BIT bit(nums.size());
        vector<int> res(nums.size());
        for(int i = nums.size() - 1; i >= 0; i--){
            res[i] = bit.query(nums[i] - 1);
            bit.update(nums[i]);
        }
        return res;
    }
};