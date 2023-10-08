// https://leetcode.com/contest/weekly-contest-366/problems/minimum-processing-time/

class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        multiset<int> s;
        for(int t:tasks){
            s.insert(-t);
        }
        auto it = s.begin();
        int res = 0;
        for(int i = 0; i < processorTime.size(); i++){
            for(int j = 0; j < 4; j++){
                res = max(res, processorTime[i] - (*it));
                it++;
            }
        }
        return res;
    }
};