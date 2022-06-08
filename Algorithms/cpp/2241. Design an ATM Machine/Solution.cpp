// https://leetcode.com/problems/design-an-atm-machine/

class ATM {
public:
    vector<long> remain;
    vector<long> val;
    
    ATM() {
        remain = vector<long>(5, 0);
        val = {20, 50, 100, 200, 500};
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0; i < 5; i++){
            remain[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<long> temp = remain;
        vector<int> res(5, 0);
        for(int i = 4; i >=0; i--){
            res[i] = min(temp[i], amount/val[i]);
            amount -= res[i]*val[i];
            temp[i] -= res[i];
        }
        if(amount != 0) return {-1};
        remain = temp;
        return res;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */