// https://leetcode.com/problems/design-underground-system/

class UndergroundSystem {
private:
    unordered_map<string, int> stat2total, stat2cnt;
    unordered_map<int, int> cust2time;
    unordered_map<int, string> cust2stat;
public:
    
    void checkIn(int id, string stationName, int t) {
        cust2time[id] = t;
        cust2stat[id] = stationName;
    }
    
    void checkOut(int id, string stationName, int t) {
        string start = cust2stat[id];
        string ste = start + "-" + stationName; // combine the start station and end station to one string
        stat2total[ste] += (t - cust2time[id]);
        stat2cnt[ste]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string ste = startStation + "-" + endStation;
        return stat2total[ste]/(double)stat2cnt[ste];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */