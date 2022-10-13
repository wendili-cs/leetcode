// https://leetcode.com/problems/design-a-leaderboard/

class Leaderboard {
private:
    unordered_map<int, int> p2s; // player id -> score
    map<int, int> s2c; // counter (number of people) for each score
public:
    void addScore(int playerId, int score) {
        int prev_score = p2s[playerId];
        if(prev_score > 0){
            s2c[prev_score]--;
        }
        p2s[playerId] = prev_score + score;
        s2c[prev_score + score]++;
    }
    
    int top(int K) {
        int sum = 0;
        auto it = s2c.rbegin();
        while(K > 0){
            int cur = min(K, it->second);
            K -= cur;
            sum += cur * it->first;
            it++;
        }
        return sum;
    }
    
    void reset(int playerId) {
        int score = p2s[playerId];
        p2s[playerId] = 0;
        s2c[score]--;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */