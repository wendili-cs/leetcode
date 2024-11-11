// https://leetcode.com/problems/minimum-array-end/

class Solution {
public:
    long long minEnd(int n, int x) {
        long res = x, v = n - 1;
        // 合并x和v：对于x的pos位如果为0，从右往左查看v的bit，
        // 如果是0则放弃合并，如果是1则将x的pos位设置为1
        // 例如：x: [0101], v: [0010]
        // 从右往左查看x，x的第二个bit是0，但是此时v的第一个bit是0，所以跳过
        // 继续从右往左查看，x的第四个bit是0，此时v的第二个bit是1，所以设置此bit为1
        // 所以最后x: [1101]
        for(int i = 0; i < 64; i++){
            long pos = (long)1 << i;
            if(!(res & pos)){
                if(v & 1) res |= pos;
                v >>= 1;
            }
        }
        return res;
    }
};