class LRUCache {
private:
    unordered_map<int, int> mp;
    unordered_map<int, list<int>::iterator> k2l;
    list<int> dll;
    int size;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    void update_used(int key){
        // move the key to the top (if exists), otherwise add the key to the top
        dll.push_front(key);
        if(k2l.find(key) != k2l.end()){
            auto it = k2l[key];
            dll.erase(it);
        }
        k2l[key] = dll.begin();
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        update_used(key);
        return mp[key];
    }
    
    void put(int key, int value) {
        update_used(key);
        mp[key] = value;
        if(dll.size() > size){
            auto it = dll.rbegin();
            mp.erase(*it);
            k2l.erase(*it);
            dll.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */