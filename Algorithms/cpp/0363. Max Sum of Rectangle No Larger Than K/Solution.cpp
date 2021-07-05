// https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/

// 要点：预求和matrix，再使用双指针处理一个维度。用有序集合处理另一个维度
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 1; j < n; j++){
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        int res = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                set<int> s;
                s.insert(0);
                int psum = 0;
                // 要让psum - x <= K  =>  x >= psum - K
                for(int t = 0; t < m; t++){
                    psum += matrix[t][j] - (i==0?0:matrix[t][i - 1]);
                    auto iter = s.lower_bound(psum - k);
                    if(iter != s.end()) res = max(res, psum - *iter);
                    s.insert(psum);
                }
            }
        }
        return res;
    }
};