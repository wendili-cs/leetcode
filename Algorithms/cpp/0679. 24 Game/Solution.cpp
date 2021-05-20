// https://leetcode-cn.com/problems/24-game/

class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        const float prec = 1e-3;
        const int ADD = 1, MULTI = 2, MINUS = 3, DIVI = 4;
        vector<float> l(cards.begin(), cards.end());
        function<bool(vector<float>&)> recur; // 随机选取两个元素“反应”，直到vector中剩下最后一个，如果不是24就继续
        recur = [&](vector<float> &v) -> bool {
            int len = v.size();
            // if(len == 0) return false;
            if(len == 1) return fabs(24.0 - v[0]) < prec;
            for(int i = 0; i < len; i++){
                for(int j = 0; j < len; j++){
                    if(i == j) continue;
                    vector<float> v_in;
                    for(int k = 0; k < len; k++){
                        if(k != i && k != j){
                            v_in.push_back(v[k]); // 搜集剩余用不上的元素
                        }
                    }
                    for(int k = 1; k <= 4; k++){
                        if(k <= 2 && i < j) continue;
                        if(k == ADD) v_in.push_back(v[i] + v[j]);
                        else if(k == MULTI) v_in.push_back(v[i] * v[j]);
                        else if(k == MINUS) v_in.push_back(v[i] - v[j]);
                        else if(k == DIVI){
                            if(fabs(v[j]) < prec) continue;
                            v_in.push_back(v[i] / v[j]);
                        }
                        if(recur(v_in))
                            return true;
                        v_in.pop_back();
                    }
                }
            }
            return false;
        };
        return recur(l);
    }
};