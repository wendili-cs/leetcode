// https://leetcode-cn.com/problems/robot-bounded-in-circle/

class Solution {
public:
    int turn(int dir, int add) {
        int ret = dir + add;
        if(ret < 0) ret += 4;
        else if(ret > 3) ret -= 4;
        return ret;
    }
    bool isRobotBounded(string instructions) {
        vector<int> move_vec(3, 0); // 最后一个是方位，0是北，1是东，2是南，3是西
        for(char& c:instructions){
            if(c == 'G') {
                if(move_vec.back() == 0 || move_vec.back() == 2) move_vec[1] += (move_vec.back()==0?1:-1);
                else move_vec[0] += (move_vec.back()==1?1:-1);
            }
            else if(c == 'L') move_vec.back() = turn(move_vec.back(), -1);
            else if(c == 'R') move_vec.back() = turn(move_vec.back(), 1);
        }
        if((move_vec[0]==0 && move_vec[1]==0)||move_vec.back()!=0) return true;
        return false;
    }
};