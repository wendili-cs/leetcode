// https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/

class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int>> mp;
    vector<int> arr;
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool ret = mp[val].empty();
        arr.push_back(val);
        mp[val].insert(arr.size() - 1);
        return ret;
    }
    
    bool remove(int val) {
        if(mp[val].empty()) return false;
        int idx = *(mp[val].begin()), last = arr.back();
        arr[idx] = last; // copy last to the idx position
        mp[val].erase(mp[val].begin());
        mp[last].insert(idx);
        mp[last].erase(arr.size() - 1);
        arr.pop_back();
        return true;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */