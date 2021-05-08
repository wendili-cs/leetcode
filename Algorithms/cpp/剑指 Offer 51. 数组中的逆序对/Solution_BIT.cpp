// https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof

class BIT {
private:
    vector<int> tree;
    int n;

public:
    BIT(int _n): n(_n), tree(_n + 1) {}

    static int lowbit(int x) {
        return x & (-x);
    }

    int query(int x) {
        int ret = 0;
        while (x) {
            ret += tree[x];
            x -= lowbit(x);
        }
        return ret;
    }

    void update(int x) {
        while (x <= n) {
            ++tree[x];
            x += lowbit(x);
        }
    }
};

class Solution {
public:
    static void get_rank(vector<int>& nums){
        int len = nums.size();
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        for(int& num:nums){
            num = lower_bound(temp.begin(), temp.end(), num) - temp.begin() + 1;
        }
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        // 离散化
        get_rank(nums);
        // 树状数组统计逆序对
        BIT bit(n);
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans += bit.query(nums[i] - 1);
            bit.update(nums[i]);
        }
        return ans;
    }
};