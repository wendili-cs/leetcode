// https://leetcode.com/problems/number-of-distinct-islands/

public class Solution {
    public void dfs(ref int[][] grid, int x, int y, char c, ref string curIsland){
        grid[x][y] = -1; // 标记为visited
        curIsland = curIsland + c;
        // 从一个点按照右、下、左、上的顺序遍历
        int [,] dirs = new int [4,2] {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        char [] dirc = new char[]{'r', 'd', 'l', 'u'};
        int m = grid.Length, n = grid[0].Length;
        for(int i = 0; i < 4; i++){
            int nx = x + dirs[i, 0], ny = y + dirs[i, 1];
            if(0 <= nx && nx < m && 0 <= ny && ny < n && grid[nx][ny] == 1){
                dfs(ref grid, nx, ny, dirc[i], ref curIsland);
            }
        }
        curIsland = curIsland + '0'; // 加结尾
    }

    public int NumDistinctIslands(int[][] grid) {
        HashSet<string> set = new HashSet<string>();
        string curIsland;
        for(int i = 0; i < grid.Length; i++){
            for(int j = 0; j < grid[0].Length; j++){
                if(grid[i][j] == 1){
                    curIsland = "";
                    dfs(ref grid, i, j, 'S', ref curIsland);
                    set.Add(curIsland);
                }
            }
        }
        return set.Count;
    }
}