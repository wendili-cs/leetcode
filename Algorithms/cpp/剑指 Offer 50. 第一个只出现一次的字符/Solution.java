// https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/

class Solution {
    public char firstUniqChar(String s) {
        HashMap<Character, Integer> mp = new HashMap();
        for(int i = 0; i < s.length(); i++){
            char t = s.charAt(i);
            if(mp.containsKey(t)){
                int cnt = mp.get(t);
                mp.put(t, ++cnt);
            }
            else mp.put(t, 1);
            
        }
        for(int i = 0; i < s.length(); i++)
            if(mp.get(s.charAt(i)) == 1) return s.charAt(i);
        return ' ';
    }
}