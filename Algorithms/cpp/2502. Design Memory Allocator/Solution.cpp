// https://leetcode.com/problems/design-memory-allocator/

class Allocator {
private:
    unordered_map<int, vector<int>> allocated;
    vector<bool> mem;
    int capacity;
public:
    Allocator(int n) {
        capacity = n;
        mem = vector<bool>(n, false);
    }
    
    int allocate(int size, int mID) {
        int cnt = 0, cur = 0;
        for(; cur < capacity; cur++){
            if(!mem[cur]){
                cnt++;
                if(cnt >= size){
                    break;
                }
            }
            else{
                cnt = 0;
            }
        }
        if(cur == capacity || cnt < size) return -1;
        // now cur is the last allocated index
        for(int i = cur; i > cur - size; i--){
            mem[i] = true;
            allocated[mID].push_back(i);
        }
        return cur - size + 1;
    }
    
    int free(int mID) {
        for(int i:allocated[mID]){
            mem[i] = false;
        }
        int ret = allocated[mID].size();
        allocated.erase(mID);
        return ret;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */