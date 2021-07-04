// https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/

// 要点：逐次对比是否存在两个数使得其在a[i:]、b[i:]上相同，有相同的这一位是1，对比下一位；
// 无相同的这一位是0，对比下一位。
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        const int MAX_BITS = 30;
        int x = 0;
        unordered_set<int> uset;
        for(int i = MAX_BITS; i >= 0; i--){
            uset.clear();
            int x_new = (x << 1) + 1;
            bool flag = false; // 是否找到使得x这一位取1的一对
            for(int num:nums) uset.insert(x_new^(num >> i));
            for(int num:nums){
                if(uset.find(num >> i) != uset.end()){
                    flag = true;
                    break;
                }
            }
            if(!flag) x = x_new - 1;
            else x = x_new;
        }
        return x;
    }
};