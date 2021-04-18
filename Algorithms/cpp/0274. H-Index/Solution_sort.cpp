// https://leetcode-cn.com/problems/h-index/submissions/

class Solution {
public:
    static bool cmp(const int& num1, const int& num2){
        return num1 > num2;
    }

    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), cmp);
        int h_index;
        for(int i = 0; i < citations.size(); i++){
            if(citations[i] < i + 1){
                h_index = i;
                break;
            }
        }
        return h_index;
    }
};