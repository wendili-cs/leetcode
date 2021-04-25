// https://leetcode-cn.com/problems/queue-reconstruction-by-height/

class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        if(a[0] == b[0]) return a[1] > b[1];
        else return a[0] < b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int len = people.size();
        vector<vector<int> > res(len);
        sort(people.begin(), people.end(), cmp);
        for(const auto& p : people){
            int count = 0;
            for(int i = 0; i < len; i++){
                if(res[i].empty()){
                    if(count == p[1]){
                        res[i] = p;
                        break;
                    }
                    count += 1;
                }
            }
        }
        return res;
    }
};