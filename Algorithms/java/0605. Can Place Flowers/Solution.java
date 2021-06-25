// https://leetcode-cn.com/problems/can-place-flowers/

class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int cnt = 1;
        for(int i = 0; i <= flowerbed.length; i++){
            if(i == flowerbed.length || flowerbed[i] == 0){
                cnt++;
            }
            else cnt = 0;
            if(cnt >= 3){
                cnt -= 2;
                n--;
            }
        }
        return n <= 0;
    }
}