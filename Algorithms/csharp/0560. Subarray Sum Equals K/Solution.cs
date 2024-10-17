// https://leetcode.com/problems/subarray-sum-equals-k/

public class Solution {
    public int SubarraySum(int[] nums, int k) {
        Dictionary<int, int> mp = new Dictionary<int, int>();
        mp.Add(0, 1);
        int res = 0;
        for(int i = 0; i < nums.Length; i++){
            if(i > 0){
                nums[i] += nums[i - 1];
            }
            if(mp.ContainsKey(nums[i] - k)) {
                res += mp[nums[i] - k];
            }
            if(mp.ContainsKey(nums[i])){
                mp[nums[i]]++;
            }
            else{
                mp[nums[i]] = 1;
            }
        }
        return res;
    }
}