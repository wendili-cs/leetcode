// https://leetcode.com/problems/minimize-xor/

class Solution {
    public int minimizeXor(int num1, int num2) {
        int cnt1 = 0, cnt2 = 0, tmp = num1;
        while(num2 > 0){
            if((num2 & 1) > 0) cnt2++;
            num2 >>= 1;
        }
        while(tmp > 0){
            if((tmp & 1) > 0) cnt1++;
            tmp >>= 1;
        }
        if(cnt1 == cnt2) return num1;
        else if(cnt1 < cnt2){
            // 基于num1，从右往左填充1直到cnt1 == cnt2
            // num1: 100100110, cnt2-cnt1 = 3
            //    x: 111110110
            int cur = 1, remain = cnt2 - cnt1;
            while(remain > 0){
                if((cur & num1) == 0){
                    num1 += cur;
                    remain--;
                }
                cur <<= 1;
            }
            return num1;
        }
        else{
            // 从左往右把二进制下num1的1一个个搬过来到x上
            // num1: 1101101, cnt2 = 4
            // x:    1101100
            int x = 0, cur = 1 << 30;
            while(cnt2 > 0){
                if((cur & num1) > 0) {
                    x += cur;
                    cnt2--;
                }
                cur >>= 1;
            }
            return x;
        }
    }
}