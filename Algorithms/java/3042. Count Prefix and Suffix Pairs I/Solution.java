// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/

class Solution {
    public boolean isPrefixAndSuffix(String str1, String str2) {
        if(str1.length() > str2.length()) return false;
        for(int i = 0; i < str1.length(); i++){
            int suffix_idx = str2.length() - str1.length() + i;
            if(str1.charAt(i) != str2.charAt(i) || str1.charAt(i) != str2.charAt(suffix_idx)) {
                return false;
            }
        }
        return true;
    }

    public int countPrefixSuffixPairs(String[] words) {
        int res = 0;
        for(int i = 0; i < words.length; i++){
            for(int j = i + 1; j < words.length; j++){
                if(isPrefixAndSuffix(words[i], words[j])){
                    res++;
                }
            }
        }
        return res;
    }
}