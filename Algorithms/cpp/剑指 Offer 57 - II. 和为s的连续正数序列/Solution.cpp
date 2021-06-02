// https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int> > res;
        int len = sqrt(2*target);
        // len = len*len==2*target? 
        for(int i = len; i >= 2; i--){ // (start + end)*(end - start + 1) = 2*target, end = start + i - 1
        // (2*start + i - 1)*i = 2*target, start = ((2*target)/i + 1 - i)/2
            if(2*target%i == 0){
                int start_2 = ((2*target)/i + 1 - i);
                if(!(start_2 & 1)){
                    int start = start_2/2;
                    vector<int> temp;
                    for(int j = start; j < start + i; j++){
                        temp.push_back(j);
                    }
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};