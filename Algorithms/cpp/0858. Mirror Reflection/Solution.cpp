// https://leetcode.com/problems/mirror-reflection/
// Explaination: https://leetcode.com/problems/mirror-reflection/discuss/146336

class Solution {
public:
    int mirrorReflection(int p, int q) {
        // we just need to figure out in which integer point (m, n) will <p, q> ray first meets
        // that would be the lowest common multiple / {p or q}
        int m = lcm(p, q)/p, n = lcm(p, q)/q;
        if((m&1) && (n&1)) return 1; // right upper one
        else if((m&1) && !(n&1)) return 2; // p = 2, q = 1 -> m = 1, n = 2 -> (2)
        else return 0; // if(!(m&1) && (n&1))
    }
};