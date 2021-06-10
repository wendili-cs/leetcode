// https://leetcode-cn.com/problems/longest-palindrome/

class Solution {
    public int longestPalindrome(String s) {
        int[] cnts = new int[60];
        for(int i = 0; i < s.length(); i++){
          int idx = s.charAt(i); 
          cnts[idx - 'A']++; 
        }
        int res = 0;
        boolean center_char = false;
        for(int cnt:cnts){
            res += cnt/2*2;
            if((cnt & 1) == 1) center_char = true;
        }
        return center_char? res + 1: res;
    }
}