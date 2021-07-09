// https://leetcode-cn.com/problems/maximum-number-of-events-that-can-be-attended/

// 要点：
//     1. 维护一个从开始日期查询event idx，(d，[idx for events if events[idx][0]==d])的map；
//     2. 维护一个从结束日期查询event idx，(d + 1，[idx for events if events[idx][1]==d])的map；
//     3. 维护一个set pair，格式为(events[idx][1], idx)
//     4. 开始数日子，对于每个日子d，在S中添加进去所有新开始会议，同时删除前一天结束了的会议
//     5. 如果此时S不是空的，证明可以将今天安排一个会议，安排S.begin()即可（因为第一个是最早结束的，尽早安排）
class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b) {
        return a[0]==b[0]? a[1] < b[1]:a[0] < b[0];
        // return a[1]==b[1]?a[0] < b[0]:a[1] < b[1];
    }
    int maxEvents(vector<vector<int>>& events) {
        map<int, vector<int> > in, out;
        set<pair<int, int> >S;
        int len = events.size(), days = 0, res = 0;
        for(int i = 0; i < len; i++){
            in[events[i][0]].push_back(i);
            out[events[i][1] + 1].push_back(i);
            days = max(days, events[i][1]);
        }
        for(int d = 1; d <= days; d++){
            for(auto idx:in[d]) S.insert(make_pair(events[idx][1], idx));
            for(auto idx:out[d]){
                auto iter = S.find(make_pair(events[idx][1], idx));
                if(iter != S.end()) S.erase(iter);
            }
            if(!S.empty()){
                S.erase(S.begin());
                res++;
            }
        }
        return res;
    }
};