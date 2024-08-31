// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
private:
    priority_queue<int> pq1; // max heap
    priority_queue<int, vector<int>, greater<int>> pq2; // min heap
public:
    
    void addNum(int num) {
        pq1.push(num);
        pq2.push(pq1.top());
        pq1.pop();
        if(pq1.size() < pq2.size()){
            pq1.push(pq2.top());
            pq2.pop();
        } // pq1.size() >= pq2.size()
    }
    
    double findMedian() {
        if(pq1.size() > pq2.size()) return (double)pq1.top();
        return (pq1.top() + pq2.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */