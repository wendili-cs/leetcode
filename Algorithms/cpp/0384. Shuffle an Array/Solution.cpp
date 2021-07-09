// https://leetcode-cn.com/problems/shuffle-an-array/

class Solution {
private:
    vector<int> ori;
public:
    Solution(vector<int>& nums) {
        ori = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return ori;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        // 洗牌算法：第n张随机插入前面0~n的前面，n表示不交换
        vector<int> shuff = ori;
        for(int i = 0; i < ori.size(); i++){
            int idx = rand() % (i + 1);
            if(idx != i) swap(shuff[i], shuff[idx]);
        }
        return shuff;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */