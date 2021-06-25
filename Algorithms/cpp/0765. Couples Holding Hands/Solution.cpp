// https://leetcode-cn.com/problems/couples-holding-hands/

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        vector<int> bcj(row.size());
        for(int i = 0; i < row.size(); i++) bcj[i] = i;
        function<int(int)> find;
        find = [&](int x) -> int {
            if(bcj[x] != x) bcj[x] = find(bcj[x]);
            return bcj[x];
        };
        function<void(int, int)> merge = [&](int x, int y) {
            bcj[find(y)] = find(bcj[x]);
        };
        for(int i = 0; i < row.size(); i++){
            if(i%2==0) merge(i, i + 1);
        }
        for(int i = 0; i < row.size()/2; i++){
            merge(row[2*i], row[2*i + 1]);
        }
        set<int> s;
        for(int i = 0; i < row.size(); i++){
            s.insert(find(i));
        }
        return row.size()/2 - s.size();
    }
};