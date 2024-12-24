// https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int numSwaps(int[] arr) {
        int ret = 0;
        int[] target = arr.clone();
        Arrays.sort(target);
        HashMap<Integer, Integer> mp = new HashMap<>();
        for(int i = 0; i < arr.length; i++){
            mp.put(arr[i], i);
        }
        for(int i = 0; i < arr.length; i++){
            if(arr[i] != target[i]){
                // 把当前位置的数字和目标位置交换
                int to = mp.get(target[i]); // 要去的位置
                arr[to] = arr[i]; // 其实是交换位置，但是arr[i]用不上了
                mp.put(arr[i], to);
                // mp[target[i]]不用更新了，因为也用不上了
                ret++;
            }
        }
        return ret;
    }

    public int minimumOperations(TreeNode root) {
        int res = 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            int qsize = q.size();
            int [] arr = new int[qsize];
            for(int i = 0; i < qsize; i++){
                TreeNode node = q.poll();
                arr[i] = node.val;
                if(node.left != null) q.add(node.left);
                if(node.right != null) q.add(node.right);
            }
            res += numSwaps(arr);
        }
        return res;
    }
}