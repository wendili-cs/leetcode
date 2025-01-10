// https://leetcode.com/problems/word-subsets/

class Solution {
    public List<String> wordSubsets(String[] words1, String[] words2) {
        int[][] cnter = new int[words1.length][26];
        int[] thres = new int[26]; // 我们只用找word2里面每个字母最高出现频率即可
        for(int i = 0; i < words1.length; i++){
            for(int j = 0; j < words1[i].length(); j++){
                cnter[i][words1[i].charAt(j) - 'a']++;
            }
        }
        for(int i = 0; i < words2.length; i++){
            int[] tmp = new int[26];
            for(int j = 0; j < words2[i].length(); j++){
                int c = words2[i].charAt(j) - 'a';
                thres[c] = Math.max(++tmp[c], thres[c]);
            }
        }
        List<String> res = new ArrayList<>();
        for(int i = 0; i < words1.length; i++){
            boolean isUniversal = true;
            for(int j = 0; j < 26; j++){
                if(cnter[i][j] < thres[j]){
                    isUniversal = false;
                    break;
                }
            }
            if(isUniversal) res.add(words1[i]);
        }
        return res;
    }
}