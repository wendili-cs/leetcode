// https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        queue<int> q;
        q.push(0);
        set<int> s;
        int res = 0;
        while(!q.empty()){
            int q_size = q.size();
            res++;
            for(int i = 0; i < q_size; i++){
                int idx = q.front();
                q.pop();
                for(int j = nums[idx]; j >= 1; j--){
                    int next = idx + j;
                    if(next >= nums.size() - 1) return res;
                    else if(s.find(idx + j) != s.end()) continue;
                    else{
                        q.push(next);
                        s.insert(next);
                    }
                }
            }
            
        }
        return 0;
    }
};