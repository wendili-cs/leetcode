// https://leetcode.com/problems/design-an-ordered-stream/

class OrderedStream {
private:
    vector<string> arr;
    int cur;
public:
    OrderedStream(int n) {
        arr = vector<string>(n);
        cur = 0;
    }
    
    vector<string> insert(int idKey, string value) {
        arr[idKey - 1] = value;
        vector<string> ret;
        while(cur < arr.size() && !arr[cur].empty()){
            ret.push_back(arr[cur]);
            cur++;
        }
        return ret;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */