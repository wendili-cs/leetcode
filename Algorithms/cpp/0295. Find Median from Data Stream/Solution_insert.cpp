// https://leetcode-cn.com/problems/find-median-from-data-stream/

class MedianFinder {
public:
    vector<int> ol_list;
    
    void addNum(int num) {
        if(ol_list.empty()){
            ol_list.push_back(num);
        }
        else{
            ol_list.insert(lower_bound(ol_list.begin(), ol_list.end(), num), num);
        }
    }
    
    double findMedian() {
        int len = ol_list.size();
        return len & 1? ol_list[len/2]: (ol_list[len/2-1] + ol_list[len/2])*0.5;
    }
};