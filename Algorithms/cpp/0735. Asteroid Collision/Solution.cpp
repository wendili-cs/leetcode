// https://leetcode.com/problems/asteroid-collision/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for(int& aster:asteroids){
            if(stk.empty() || aster > 0) stk.push(aster);
            else{
                while(!stk.empty() && stk.top() > 0 && aster < 0){
                    // 左边正数右边负数，发生碰撞
                    int cur = stk.top();
                    if(cur <= abs(aster)) stk.pop(); // 旧的陨石没了
                    if(cur >= abs(aster)) { // 新的陨石没了
                        aster = 0;
                        break;
                    };
                }
                if(aster != 0) stk.push(aster);
            }
        }
        vector<int> res;
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};