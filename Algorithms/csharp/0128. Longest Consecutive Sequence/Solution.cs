// https://leetcode.com/problems/longest-consecutive-sequence/

public class Solution {
    public int LongestConsecutive(int[] nums) {
        HashSet<int> s = new HashSet<int>();
        for(int i = 0; i < nums.Length; i++){
            s.Add(nums[i]);
        }
        int res = 0;
        foreach(int num in s){
            if(!s.Contains(num - 1)){
                int x = num, tmp = 0;
                while(s.Contains(x)){
                    tmp++;
                    x++;
                }
                res = Math.Max(res, tmp);
            }
        }
        return res;
    }
}