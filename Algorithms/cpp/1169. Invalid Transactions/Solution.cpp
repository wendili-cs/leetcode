// https://leetcode.com/problems/invalid-transactions/
// not hard, but the process is very long for C++

struct tran {
    string name;
    int time;
    int amount;
    string city;
    
    // if we use map<tran, string>, then this is necessary
    bool operator<(const tran& co) const{
        return amount < co.amount;
    }
    bool operator==(const tran& co) const{
        return amount == co.amount && name == co.name
            && time == co.time && city == co.city;
    }
};

class Solution {
public:
    static bool cmp(tran &a, tran &b) {
        return a.time < b.time;
    }
    
    vector<string> invalidTransactions(vector<string>& transactions) {
        // map<tran, string> to_str;
        auto parse_tran = [&](string stran) -> tran {
            tran t;
            int l = 0, r = 0;
            vector<string> tmp;
            for(r = 0; r < stran.length(); r++){
                if(stran[r] == ','){
                    tmp.push_back(stran.substr(l, r - l));
                    l = r + 1;
                }
            }
            tmp.push_back(stran.substr(l, r - l));
            t.name = tmp[0];
            t.time = stoi(tmp[1]);
            t.amount = stoi(tmp[2]);
            t.city = tmp[3];
            // to_str[t] = stran;
            return t;
        };
        vector<tran> trans;
        for(string &stran:transactions){
            trans.push_back(parse_tran(stran));
        }
        auto to_str = [](tran &t) -> string {
            string ret;
            ret += t.name + ",";
            ret += to_string(t.time) + ",";
            ret += to_string(t.amount) + ",";
            ret += t.city;
            return ret;
        };
        sort(trans.begin(), trans.end(), cmp);
        unordered_map<string, vector<int>> mp; // name to trans index
        unordered_set<int> res_idx;
        for(int i = 0; i < trans.size(); i++){
            if(trans[i].amount > 1000) res_idx.insert(i);
            if(mp.find(trans[i].name) != mp.end()){
                for(int idx:mp[trans[i].name]){
                    if(trans[idx].city != trans[i].city && 
                       trans[idx].time >= trans[i].time - 60){
                        res_idx.insert(i);
                        res_idx.insert(idx);
                    }
                }
            }
            mp[trans[i].name].push_back(i);
        }
        vector<string> res;
        for(auto it:res_idx){
            res.push_back(to_str(trans[it]));
        }
        return res;
    }
};