// https://leetcode-cn.com/problems/adding-two-negabinary-numbers/

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res(max(arr1.size(), arr2.size()) + 2, 0);
        auto iter1 = arr1.rbegin(), iter2 = arr2.rbegin();
        for(int i = res.size() - 1; i >= 0; i--){
            int sum = res[i];
            if(iter1 != arr1.rend()) sum += *iter1++;
            if(iter2 != arr2.rend()) sum += *iter2++;
            if(sum == -1){
                sum += 2;
                res[i - 1]++;
            }
            else if(sum >= 2){
                sum -= 2;
                res[i - 1]--;
            }
            res[i] = sum;
        }
        auto iter = res.begin();
        while(*iter == 0 && iter + 1 != res.end()){
            iter = res.erase(iter);
        }
        return res;
    }
};