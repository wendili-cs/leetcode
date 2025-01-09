// https://leetcode.com/problems/counting-words-with-a-given-prefix/

class Solution {
    public int prefixCount(String[] words, String pref) {
        int res = 0;
        for(int i = 0; i < words.length; i++){
            if(words[i].indexOf(pref) == 0){
                res++;
            }
        }
        return res;
    }
}