// https://leetcode-cn.com/problems/length-of-last-word/

class Solution {
    public int lengthOfLastWord(String s) {
        int r = -1, l = -1;
        for(int i = s.length() - 1; i >= 0; i--){
            if(s.charAt(i) != ' '){
                if(r == -1) r = i;
            }
            else if(s.charAt(i) == ' ' && l == -1 && r != -1) l = i + 1;
            if(i == 0 && l == -1 && r != -1) l = i;
        }
        return r == -1? 0:r - l + 1;
    }
}