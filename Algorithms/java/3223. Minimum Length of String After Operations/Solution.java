// https://leetcode.com/problems/minimum-length-of-string-after-operations/

class Solution {
    public int minimumLength(String s) {
        int res = s.length();
        HashMap<Character, Integer> mp = new HashMap<>();
        for(char c:s.toCharArray()){
            mp.put(c, mp.getOrDefault(c, 0) + 1);
            // 如果大于等于3，减去2(mod 2)
            if(mp.getOrDefault(c, 0) >= 3){
                res -= 2;
                mp.put(c, mp.get(c) - 2);
            }
        }
        return res;
    }
}