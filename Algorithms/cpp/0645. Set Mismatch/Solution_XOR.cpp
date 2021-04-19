// https://leetcode-cn.com/problems/set-mismatch

// 来源解释：题解的评论：
// 缺失数记为miss，重复数记为dump
// 1. 对数组所有元素及1~n范围内数进行异或运算，得到miss^dump 记为xor； 相同值异或为0，0同任何值异或仍为原值；
// 2. xor二进制形式右数第一个值为1的位记为mostrightbit，使用xor&(~(xor - 1))取出该位 替换掉xor； 因为miss不等于dump 所以xor二进制一定有等于1的位，xor&(~(xor - 1))能取出该位 是因为该位右侧全为0 减1取非再取与后保持不变 该位左侧不会减1 取非再取与后全置为0；
// 3. xor同数组内所有元素及1~n范围内数取与，值为0的相互异或 记为xor0，值为1的相互异或 记为xor1，xor0 xor1即为miss dump； mostrightbit=1说明该位上miss和dump值不同 分别处于上面划分的两拨中，一拨会有三个dump 一拨会有一个miss 两拨其余数都会出现两次 异或后得到dum和miss；
// 4. 遍历数组 存在元素等于xor0 则xor0为dump 否则为miss；

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int XOR = 0, duplicate = 0, missing = 0;
        for (const auto& num : nums) {
            XOR = XOR ^ num;
        }
        for (int i = 1; i <= nums.size(); i++) {
            XOR = XOR ^ i;
        }
        int rightmostbit = XOR & ~(XOR - 1);
        for (const auto& num : nums) {
            if ((num & rightmostbit) != 0) {
                missing ^= num;
            }
            else {
                duplicate ^= num;
            }
        }
        for (int i = 1; i <= nums.size(); i++) {
            if ((i & rightmostbit) != 0) {
                missing ^= i;
            }
            else {
                duplicate ^= i;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == duplicate) {
                return {duplicate, missing};
            }
        }
        return {missing, duplicate};
    }
};