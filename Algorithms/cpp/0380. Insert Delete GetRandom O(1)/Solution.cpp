// https://leetcode.com/problems/insert-delete-getrandom-o1/

class RandomizedSet {
private:
    unordered_map<int, int> mp; // from value to index
    vector<int> arr;
public:
    bool insert(int val) {
        if(mp.find(val) == mp.end()){
            arr.push_back(val);
            mp[val] = arr.size() - 1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val) != mp.end()){
            // 和最后一个元素交换，更新mp，再pop back
            swap(arr.back(), arr[mp[val]]);
            mp[arr[mp[val]]] = mp[val];
            mp.erase(val);
            arr.pop_back();
            return true;
        }
        return false;
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