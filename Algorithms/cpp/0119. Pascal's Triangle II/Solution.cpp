// https://leetcode-cn.com/problems/pascals-triangle-ii/

// 直接使用组合公式C(n,i) = n!/(i!*(n-i)!)
// 则第(i+1)项是第i项的倍数=(n-i)/(i+1);
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        long cur = 1;
        for(int i = 0; i <= rowIndex; i++){
            if(i > rowIndex/2){
                res[i] = res[rowIndex - i];
                continue;
            }
            res[i] = cur;
            cur = cur*(rowIndex - i)/(i + 1);
        }
        return res;
    }
};