// https://leetcode.com/problems/max-chunks-to-make-sorted/

class Solution {
    public int maxChunksToSorted(int[] arr) {
        int res = 0, n = arr.length, prefixSum = 0, sortedPrefixSum = 0;
        // 每次找到k使得sum(arr[:k]) == sum(0 + 1 + ... + k)的时候，可以切出一个chunk
        for(int i = 0; i < n; i++){
            prefixSum += arr[i];
            sortedPrefixSum += i;
            if(prefixSum == sortedPrefixSum){
                res++;
            }
        }
        return res;
    }
}