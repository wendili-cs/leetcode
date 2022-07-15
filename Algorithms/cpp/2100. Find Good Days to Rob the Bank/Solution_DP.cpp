// https://leetcode.com/problems/find-good-days-to-rob-the-bank/

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<bool> ni(security.size() + time, false), nd(security.size() + time, false);
        int i_inc = 0, i_dec = 0;
        if(0 - i_dec >= time) nd[0] = true;
        if(0 - i_inc >= time) ni[0] = true;
        for(int i = 1; i < security.size(); i++){
            if(security[i] > security[i - 1]) i_dec = i;
            if(security[i] < security[i - 1]) i_inc = i;
            if(i - i_dec >= time) nd[i] = true;
            if(i - i_inc >= time) ni[i] = true;
        }
        vector<int> res;
        for(int i = 0; i < security.size(); i++){
            if(ni[i + time] && nd[i]) res.push_back(i);
        }
        return res;
    }
};