// https://leetcode-cn.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool flag = false; // 找到第一个完全无交集的右边的段为止
        int left_val = newInterval[0], right_val = newInterval[1];
        vector<vector<int> > res;
        for(const auto& interval:intervals){ // 插入段左边的内容
            if(interval[1] < newInterval[0]){
                res.push_back(interval);
            }
            else if(interval[0] > newInterval[1]){ // 插入段右边的
                if(!flag){
                    res.push_back({left_val, right_val});
                    flag = true;
                }
                res.push_back(interval);
            }
            else{
                left_val = min(left_val, interval[0]);
                right_val = max(right_val, interval[1]);
            }
        }
        if(!flag){ // 在范围之外
            res.push_back({left_val, right_val});
        }

        return res;
    }
};