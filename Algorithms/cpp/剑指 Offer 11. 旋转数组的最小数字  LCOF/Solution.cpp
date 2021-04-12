// https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int ptr = numbers[0];
        for(int i = 1; i < numbers.size(); i++){
            if(ptr > numbers[i]){
                return numbers[i];
            }
            ptr = numbers[i];
        }
        return numbers[0];
    }
};