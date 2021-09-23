// https://leetcode-cn.com/problems/next-closest-time/

class Solution {
public:
    string nextClosestTime(string time) {
        vector<int> T;
        for(int i = 0; i < 5; i++)
            if (i != 2) T.push_back(time[i] - '0');
        set<int>Q (T.begin(), T.end());
        vector<int> up = {2, T[0]==2?3:9, 5, 9};
        char min_v = *Q.begin() + '0';
        int i;
        for(i = 3; i >= 0; i--){
            auto it = Q.upper_bound(T[i]);
            if(it != Q.end() && up[i] >= *it){
                time[i>1?i+1:i] = *it + '0';
                break;
            }
        }
        for(i++; i < 4; i++) time[i>1?i+1:i] = min_v;
        return time;
    }
};