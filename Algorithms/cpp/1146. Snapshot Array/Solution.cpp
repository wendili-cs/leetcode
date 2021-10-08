// https://leetcode.com/problems/snapshot-array/

class SnapshotArray {
private:
    vector<map<int, int>> arrs;
    map<int, int> update_l;
    int snap_num;
public:
    SnapshotArray(int length) {
        arrs = vector<map<int, int>>(length);
        snap_num = 0;
    }
    
    void set(int index, int val) {
        if(arrs[index].empty() || arrs[index].rbegin()->second != val){
            update_l[index] = val;
        }
    }
    
    int snap() {
        for(auto it:update_l){
            arrs[it.first][snap_num] = it.second;
        }
        update_l.clear();
        snap_num++;
        return snap_num - 1;
    }
    
    int get(int index, int snap_id) {
        if(arrs[index].find(snap_id) != arrs[index].end())
            return arrs[index][snap_id];
        for(auto it = arrs[index].rbegin(); it != arrs[index].rend(); it++){
            if(it->first <= snap_id)
                return it->second;
        }
        return 0;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */