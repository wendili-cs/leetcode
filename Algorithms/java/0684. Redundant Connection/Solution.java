// https://leetcode.com/problems/redundant-connection

class Solution {
    private int[] dset;

    public int find(int x) {
        if(dset[x] != x) dset[x] = find(dset[x]);
        return dset[x];
    }

    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        dset = new int[n];
        for(int i = 0; i < n; i++) dset[i] = i;

        for(int i = 0; i < n; i++){
            if(find(edges[i][0] - 1) == find(edges[i][1] - 1)) return edges[i];
            dset[find(edges[i][0] - 1)] = find(edges[i][1] - 1);
        }
        
        return new int[] {-1, -1};
    }
}