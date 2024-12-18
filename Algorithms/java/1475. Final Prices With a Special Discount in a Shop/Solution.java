// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/

class Solution {
    public int[] finalPrices(int[] prices) {
        int n = prices.length;
        // HashMap<Integer, Integer> nextIndex = new HashMap<Integer, Integer>();
        Stack<Integer> stk = new Stack<Integer>();
        int[] res = new int[n];
        for(int i = 0; i < n; i++){
            while(!stk.isEmpty() && prices[stk.peek()] >= prices[i]){
                res[stk.peek()] = prices[stk.peek()] - prices[i];
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.isEmpty()){
            res[stk.peek()] = prices[stk.peek()];
            stk.pop();
        }
        return res;
    }
}