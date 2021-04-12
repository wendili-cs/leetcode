class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ptr = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[ptr++] = nums[i];
            }
        }
        return ptr;
    }
};