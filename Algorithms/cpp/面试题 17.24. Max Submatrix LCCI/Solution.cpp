// https://leetcode-cn.com/problems/max-submatrix-lcci/

// 参考链接：https://blog.csdn.net/m0_46202073/article/details/115175436
// 要点：前缀和，上下边界确定y的值。对于每一行，贪心算法计算sum，当sum < 0的时候，刷新nax_sum，如果刷新则同时记下坐标。
class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), max_sum = INT_MIN;
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                matrix[i][j] += matrix[i - 1][j];
            }
        }
        vector<int> line(n), res(4);
        for(int top = 0; top < m; top++){
            for(int bottom = top; bottom < m; bottom++){
                for(int j = 0; j < n; j++) line[j] = matrix[bottom][j] - (top==0?0:matrix[top - 1][j]);
                int l = 0, r, sum = 0;
                for(int r = 0; r < n; r++){
                    if(sum < 0){
                        l = r;
                        sum = line[r];
                    }
                    else sum += line[r];
                    if(max_sum < sum){
                        res[0] = top;
                        res[1] = l;
                        res[2] = bottom;
                        res[3] = r;
                        max_sum = sum;
                    }
                }
            }
        }
        return res;
    }
};