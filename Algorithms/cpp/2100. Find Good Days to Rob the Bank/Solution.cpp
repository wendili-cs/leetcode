// https://leetcode.com/problems/find-good-days-to-rob-the-bank/

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        if(security.size() < time*2 + 1) return {};
        deque<int> front, back, in_front, in_back;
        for(int i = 0; i <= time; i++){
            while(!front.empty() && front.back() < security[i]) {
                front.pop_back();
                in_front.pop_back();
            }
            front.push_back(security[i]);
            in_front.push_back(i);
        }
        for(int i = time; i < 2*time + 1; i++){
            while(!back.empty() && back.back() > security[i]) {
                back.pop_back();
                in_back.pop_back();
            }
            back.push_back(security[i]);
            in_back.push_back(i);
        }
        vector<int> res;
        if(front.size() == time + 1 && back.size() == time + 1) res.push_back(time);
        for(int i = time + 1; i + time < security.size(); i++){
            while(!front.empty() && front.back() < security[i]){
                front.pop_back();
                in_front.pop_back();
            }
            front.push_back(security[i]);
            in_front.push_back(i);
            if(in_front.front() < i - time){
                front.pop_front();
                in_front.pop_front();
            }
            while(!back.empty() && back.back() > security[i + time]) {
                back.pop_back();
                in_back.pop_back();
            }
            back.push_back(security[i + time]);
            in_back.push_back(i + time);
            if(in_back.front() < i){
                back.pop_front();
                in_back.pop_front();
            }
            if(front.size() == time + 1 && back.size() == time + 1) res.push_back(i);
        }
        return res;
    }
};