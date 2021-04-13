// https://leetcode-cn.com/problems/3sum-closest/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size(), nearest = 1e5;

        auto update = [&target, &nearest](int new_one){ // 更新一次最接近的值
            if(abs(target - nearest) > abs(target - new_one)){
                nearest = new_one;
            }
        };

        sort(nums.begin(), nums.end());

        for(int idx_1 = 0; idx_1 < len; idx_1++){
            if(idx_1 > 0 && nums[idx_1]==nums[idx_1-1]){ // 考虑相同的一串元素，就往右滑动
               continue; 
            }
            int idx_2 = idx_1 + 1, idx_3 = len - 1;
            while(idx_2 < idx_3){
                int three_sum = nums[idx_1] + nums[idx_2] + nums[idx_3];
                if(three_sum == target){
                    return target;
                }
                update(three_sum);
                if(three_sum > target){
                    idx_3--;
                }
                else{
                    idx_2++;
                }
            }
        }

        return nearest;
    }
};