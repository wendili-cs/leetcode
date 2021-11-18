// https://leetcode.com/problems/minimum-cost-to-connect-sticks/

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        if(sticks.size() < 2) return 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int& each:sticks) pq.push(each);
        int n = sticks.size(), res = 0;
        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            pq.push(a + b);
            res += a + b;
        }
        return res;
    }
};