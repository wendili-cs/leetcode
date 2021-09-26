// https://leetcode.com/problems/time-based-key-value-store/

class TimeMap {
private:
    map<string, map<int, string> > m;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(m[key].empty()) return "";
        auto it = m[key].rbegin();
        while(it != m[key].rend() && it->first > timestamp) it++;
        return it != m[key].rend()?it->second:"";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */