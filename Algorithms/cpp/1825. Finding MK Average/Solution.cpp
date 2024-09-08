// https://leetcode.com/problems/finding-mk-average/

class MKAverage {
private:
    queue<int> stream;
    multiset<int> low, mid, high;
    int m, k;
    long sum;
public:
    MKAverage(int _m, int _k) {
        m = _m;
        k = _k;
        sum = 0;
    }
    
    void addElement(int num) {
        stream.push(num);
        if(stream.size() > m) {
            removeFromSet(stream.front());
            stream.pop();
        }
        addToSet(num);
    }

    void removeFromSet(int num) {
        if(low.find(num) != low.end()){
            low.erase(low.find(num));
        }
        else if(mid.find(num) != mid.end()){
            mid.erase(mid.find(num));
            sum -= num;
            // in this case, we should pull the largest number from its lower level, and put it from high
            if(!low.empty()){
                int low_out = *low.rbegin();
                low.erase(low.find(low_out));
                addToSet(low_out);
            }
        }
        else{
            high.erase(high.find(num));
            // pull the largest number from mid, low, and call addToSet
            if(!low.empty()){
                int low_out = *low.rbegin();
                low.erase(low.find(low_out));
                addToSet(low_out);
            }
            if(!mid.empty()){
                int mid_out = *mid.rbegin();
                mid.erase(mid.find(mid_out));
                sum -= mid_out;
                addToSet(mid_out);
            }
        }
    }

    // three sets must NOT be all full before use this function
    // num -> high --(if size overflow, pop smallest one)--> mid --(if size overflow, pop smallest one)--> low
    void addToSet(int num){
        high.insert(num);
        if(high.size() > k){
            int mid_in = *(high.begin()); // element passed from high to mid
            high.erase(high.begin());
            mid.insert(mid_in);
            sum += mid_in;
            if(mid.size() > m - 2*k){
                int mid_out = *(mid.begin()); // element passed to low from mid
                mid.erase(mid.find(mid_out));
                sum -= mid_out;
                low.insert(mid_out);
            }
        }
    }
    
    int calculateMKAverage() {
        if(low.size() + mid.size() + high.size() < m) return -1;
        return sum/(m - 2*k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */