// https://leetcode.com/problems/logger-rate-limiter/

class Logger {
private:
    map<string, int> m;
    int timer;
public:
    Logger() {
        timer = 0;
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(m.find(message) == m.end() || m[message] <= timestamp){
            m[message] = timestamp + 10;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */