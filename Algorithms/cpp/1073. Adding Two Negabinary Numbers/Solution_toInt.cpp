// https://leetcode-cn.com/problems/adding-two-negabinary-numbers/

// 直接转换成数字，无法处理过大的数字
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        auto calc = [](vector<int> &arr) -> int {
            int ret = 0, base = 1;
            for(int i = arr.size() - 1; i >= 0; i--){
                ret += ((arr.size() - i) % 2 == 1? 1:-1)*base*arr[i];
                base *= 2;
            }
            return ret;
        };
        int sum = calc(arr1) + calc(arr2);
        auto to_m2 = [](int num) -> vector<int> {
            if(num == 0) return {0};
            vector<int> ret;
            while(num != 0){
                int b = num%-2;
                ret.push_back(abs(b));
                num /= -2;
                if(b < 0) num++;
            }
            reverse(ret.begin(), ret.end());
            return ret;
        };
        return to_m2(sum);
    }
};