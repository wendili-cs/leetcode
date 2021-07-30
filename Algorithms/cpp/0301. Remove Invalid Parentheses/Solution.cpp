// https://leetcode-cn.com/problems/remove-invalid-parentheses

// remove 逻辑：
// 1. 从第 0 个位置开始向右扫描，一旦发现右括号多出来了，就必须要删除一个 [0, 当前位置] 的范围的右括号。删除掉后，[0, 当前位置] 就是一个符合条件的括号匹配，继续向右扫描，如果又遇到右括号多出来，再次从 [0, 当前位置] 删除一个右括号，这样直到所有不符合条件的右括号被删除。
// 2. 把第 1 步得到的字符串，反转，按照同样的思路，把多出来的“右括号”（算法一样，只是以前的左括号要当成右括号来处理）删除。
// 3. 经过以上 2 步的处理，最终处理的字符串就是符合要求的。

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        function<void(string, int, int, vector<int>)> remove;
        // 变量m是当前扫描的右边界，n是上一次修改的index，par是（如{'(', ')'}）衡量标准（翻转的时候颠倒）
        remove = [&](string t, int m, int n, vector<int> par) -> void {
            int stack = 0;
            for(int i = m; i < t.length(); i++){
                if(t[i] == par[0]) stack++;
                else if(t[i] == par[1]) stack--;
                if(stack < 0){ // 有多余的)，要去掉
                    for(int j = n; j <= i; j++){
                        // 不要对类似)))的情况多次操作
                        if(t[j] == par[1] && (j == n || t[j - 1] != par[1])){
                            remove(t.substr(0, j) + t.substr(j + 1), i, j, par);
                        }
                    }
                    return; // 不用考虑下一种情况了
                }
            }
            reverse(t.begin(), t.end());
            // 还没反向考虑就反向考虑一下
            if(par[0] == '(') remove(move(t), 0, 0, {par[1], par[0]});
            else res.push_back(move(t));
        };
        remove(s, 0, 0, {'(', ')'});
        return res;
    }
};

// 0 1 2 3 4 5 6 7 8 9
// ( ( ) ( ) ) ) ) ( )
//             ^ 在这里发现右括号多了一个，可以删除 s[2], s[4], s[5], s[6] 中的任意一个
//               但是 s[4], s[5], s[6] 删除后，得出来的子串都是一样的，这里还需要去重
// 删除 s[2] 后，此时 m = 6, n = 2，这条分支记为 B1
// 0 1 2 3 4 5 6 7 8
// ( ( ( ) ) ) ) ( )
//     ^n      ^m
// 删除 s[4] 后, 此时 m = 6, n = 4，这条分支记为 B2
// 0 1 2 3 4 5 6 7 8
// ( ( ) ( ) ) ) ( )
//         ^n  ^m
// 接下来分析分支B2,(分支B1你可以类似分析)，删除 s[4] 后，产生的新串会丢给新的 remove 函数，继续从位置 m = 6 处扫描，但是没有必要从头开始
// 从位置 m = 6 这里继续扫描即可，发现 s[6] 又不符合条件，于是你又得在 s[0..m] 之间找到一个右括号删除。
//
// 0 1 2 3 4 5 6 7 8
// ( ( ) ( ) ) ) ( )
//         ^n  ^m
//
// 如果你不记录 n 的值，再次进入递归的时候，你又得从位置 0 开始重新找右括号，这时候你可能会删除 s[2]，
// 这就有问题了，s[2] 删除后变成下面这样。如果你分析了一下 B1 分支，你就会发现产生了一个重复串，和下面一模一样。
// 0 1 2 3 4 5 6 7 8
// ( ( ( ) ) ) ( )
//         ^n  ^m
// 所以 B2 分支，是不能从位置 0 开始寻找右括号删除，而应该从 n 这个位置开始寻找右括号去删除。删除之后变成下面这样
// 0 1 2 3 4 5 6 7 8
// ( ( ) ( ) ) ( )
//         ^n  ^m