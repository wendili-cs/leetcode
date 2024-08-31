// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        for(int i = 0; i < n; i++){
            pq.push(make_tuple(matrix[i][0], i, 0));
        }
        for(int i = 0; i < k - 1; i++){
            auto [val, x, y] = pq.top();
            pq.pop();
            if(y + 1 < n){
                pq.push(make_tuple(matrix[x][y + 1], x, y + 1));
            }
        }
        return get<0>(pq.top());
    }
};