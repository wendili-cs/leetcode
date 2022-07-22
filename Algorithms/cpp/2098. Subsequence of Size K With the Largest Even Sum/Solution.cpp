class Solution {
public:
    long long largestEvenSum(vector<int>& nums, int k) {
        priority_queue<int> pqe, pqo;
        for(int& num:nums){
            if(num&1) pqo.push(num);
            else pqe.push(num);
        }
        long sum = 0, last_even = -1, last_odd = -1;
        for(int i = 0; i < k; i++){
            if(pqe.empty() || (!pqo.empty() && pqe.top() < pqo.top())){
                sum += pqo.top();
                last_odd = pqo.top();
                pqo.pop();
            }
            else{
                sum += pqe.top();
                last_even = pqe.top();
                pqe.pop();
            }
        }
        if(sum%2 != 0){
            long sum1 = -1, sum2 = -1;
            if(!pqe.empty() && last_odd != -1){
                sum1 = sum + pqe.top() - last_odd;
            }
            if(!pqo.empty() && last_even != -1){
                sum2 = sum + pqo.top() - last_even;
            }
            return sum1 > sum2 ? sum1 : sum2;
        }
        return sum;
    }
};