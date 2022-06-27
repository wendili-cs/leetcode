// https://leetcode.com/problems/design-bitset/

class Bitset {
public:
    int cnt_1, bsize;
    string str, str_v;
    
    Bitset(int size) {
        str = string(size, '0'), str_v = string(size, '1');
        cnt_1 = 0, bsize = size;
    }
    
    void fix(int idx) {
        if(str[idx] == '0'){
            str[idx] = '1';
            cnt_1++;
            str_v[idx] = '0';
        }
    }
    
    void unfix(int idx) {
        if(str[idx] == '1'){
            str[idx] = '0';
            cnt_1--;
            str_v[idx] = '1';
        }
    }
    
    void flip() {
        swap(str, str_v);
        cnt_1 = bsize - cnt_1;
    }
    
    bool all() {
        return cnt_1 == bsize;
    }
    
    bool one() {
        return cnt_1 != 0;
    }
    
    int count() {
        return cnt_1;
    }
    
    string toString() {
        return str;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */