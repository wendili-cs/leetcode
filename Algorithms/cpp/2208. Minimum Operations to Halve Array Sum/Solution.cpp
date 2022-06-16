// https://leetcode.com/problems/minimum-operations-to-halve-array-sum/

class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sum = 0.0;
        for(int& num:nums){
            sum += num;
            pq.push(num);
        }
        double halve = sum/2;
        int cnt = 0;
        while(sum > halve){
            sum -= pq.top()/2.0;
            pq.push(pq.top()/2.0);
            pq.pop();
            cnt++;
        }
        return cnt;
    }
};