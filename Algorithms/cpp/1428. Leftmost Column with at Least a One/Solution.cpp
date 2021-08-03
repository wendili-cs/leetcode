// https://leetcode-cn.com/problems/leftmost-column-with-at-least-a-one/

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        bool find_ans = false;
        int m = binaryMatrix.dimensions()[0], n = binaryMatrix.dimensions()[1], col = n;
        for(int i = 0; i < m; i++){
            if(binaryMatrix.get(i, min(col, n - 1)) == 0){
                continue;
            }
            if(binaryMatrix.get(i, 0) == 1) return 0;
            int l = 0, r = col, j = (r + l)/2, cur, prev; // cur在成为最左边的1的时候结束
            while(!((cur = binaryMatrix.get(i, j))==1 && (j==0||(prev = binaryMatrix.get(i, j-1))==0))){
                if(cur == 1) r = j;
                else if(cur == 0) l = j + 1;
                j = (r + l)/2;
            }
            col = j;
        }
        return col==n?-1:col;
    }
};