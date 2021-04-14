// https://leetcode-cn.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int idx_1 = 0, idx_2 = len - 1, best = 0;

        auto update = [&](){
            int volume = abs(idx_2 - idx_1)*min(height[idx_1], height[idx_2]);
            best = max(volume, best);
        };

        auto move_small = [&](){ // 每次移动数值较小的
            if(height[idx_1] > height[idx_2]){
                idx_2--;
            }
            else{
                idx_1++;
            }
        };
        
        while(idx_1 < idx_2){
            update();
            move_small();
            if(idx_1==idx_2){
                break;
            }
        }
        return best;
    }
};