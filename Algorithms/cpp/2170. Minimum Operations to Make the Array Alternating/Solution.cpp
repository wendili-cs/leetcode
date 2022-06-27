// https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int, int> mp1, mp2;
        int num1_one = -1, num1_two = -1, num2_one = -1, num2_two = -1;
        for(int i = 0; i < nums.size(); i++){
            if(i & 1){
                mp1[nums[i]]++;
                if(mp1[nums[i]] > mp1[num1_two] && nums[i] != num1_one){
                    num1_two = nums[i];
                }
                if(mp1[num1_two] > mp1[num1_one]){
                    swap(num1_two, num1_one);
                }
            }
            else{
                mp2[nums[i]]++;
                if(mp2[nums[i]] > mp2[num2_two] && nums[i] != num2_one){
                    num2_two = nums[i];
                }
                if(mp2[num2_two] > mp2[num2_one]){
                    swap(num2_two, num2_one);
                }
            }
        }
        if(num1_one != num2_one){
            return nums.size() - mp1[num1_one] - mp2[num2_one];
        }
        return min(nums.size() - mp1[num1_one] - mp2[num2_two], nums.size() - mp1[num1_two] - mp2[num2_one]);
    }
};