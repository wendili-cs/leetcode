// https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/
// https://blog.csdn.net/u011500062/article/details/72855826
// 问题： N个人编号为1，2，……，N，依次报数，每报到M时，杀掉那个人，求最后胜利者的编号。
// 递推公式：f(N,M)=(f(N−1,M)+M)%N
// f(N,M)表示，N个人报数，每报到M时杀掉那个人，最终胜利者的编号
// f(N-1,M)表示，N-1个人报数，每报到M时杀掉那个人，最终胜利者的编号

class Solution {
public:
    int lastRemaining(int n, int m) {
        int idx = 0; // 最后剩下的一个
        for(int i = 2; i <= n; i++){
            idx = (idx + m)%i;
        }
        return idx;
    }
};