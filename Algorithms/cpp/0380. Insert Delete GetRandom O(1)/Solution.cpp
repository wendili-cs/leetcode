// https://leetcode.com/problems/insert-delete-getrandom-o1/

class RandomizedSet {
public:
    vector<int> arr;
    unordered_map<int, int> us;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(us.find(val) != us.end()) return false;
        arr.push_back(val);
        us[val] = arr.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(us.find(val) == us.end()) return false;
        int idx = us[val];
        int last_ele = arr.back();
        arr.pop_back();
        arr[idx] = last_ele;
        us[last_ele] = idx;
        us.erase(val);
        return true;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */