// https://leetcode.com/problems/design-browser-history/

class BrowserHistory {
private:
    list<string> his;
    list<string>::iterator cur;
public:
    BrowserHistory(string homepage) {
        his.push_back(homepage);
        cur = his.begin();
    }
    
    void visit(string url) {
        auto nxt = next(cur);
        his.erase(nxt, his.end());
        his.push_back(url);
        cur = next(cur);
    }
    
    string back(int steps) {
        for(int i = 0; i < steps && cur != his.begin(); i++){
            cur--;
        }
        return *cur;
    }
    
    string forward(int steps) {
        for(int i = 0; i < steps && cur != prev(his.end()); i++){
            cur++;
        }
        return *cur;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */