// https://leetcode-cn.com/problems/find-median-from-data-stream/

class MedianFinder {
public:
    priority_queue<int> heap_h; // 大顶堆
    priority_queue<int, vector<int>, greater<int> > heap_l; // 小顶堆
    
    void addNum(int num) {
        heap_h.push(num);
        heap_l.push(heap_h.top());
        heap_h.pop();
        if(heap_h.size() < heap_l.size()){
            heap_h.push(heap_l.top());
            heap_l.pop();
        }
    }
    
    double findMedian() {
        return heap_h.size() > heap_l.size()? heap_h.top(): (heap_l.top() + heap_h.top())*0.5;
    }
};
