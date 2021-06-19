// https://leetcode-cn.com/problems/maximum-swap/

class Solution {
    public int maximumSwap(int num) {
        String str = Integer.toString(num);
        int len = str.length();
        if(num == 0 || len == 1) return num;
        for(int i = 0; i < len; i++){
            char a = str.charAt(i);
            int to_swap = i;
            for(int j = len - 1; j > i; j--){
                if(str.charAt(to_swap) < str.charAt(j)) to_swap = j;
            }
            if(to_swap != i){
                num -= (str.charAt(to_swap) - a)*Math.pow(10, len - to_swap - 1);
                num += (str.charAt(to_swap) - a)*Math.pow(10, len - i - 1);
                break;
            }
        }
        return num;
    }
}