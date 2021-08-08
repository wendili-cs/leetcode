// https://leetcode-cn.com/problems/find-the-celebrity/

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int a = 0;
        for(int b = 1; b < n; b++){ // 可能的名人候选人
            if(knows(a, b)) a = b;
        }
        for(int i = 0; i < n; i++){ // 确认候选人是否是名人
            if(i == a) continue;
            if(knows(a, i) || !knows(i, a)) return -1;
        }
        return a;
    }
};