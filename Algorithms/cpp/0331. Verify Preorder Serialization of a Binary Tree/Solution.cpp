// https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree/

class Solution {
public:
    bool isValidSerialization(string preorder) {
        // 空节点是叶节点，每2个空节点前面肯定是一个非叶节点（数字）
        int cnter = 0, i = preorder.length() - 1;
        while(i >= 0){
            if(preorder[i] == '#'){
                cnter++;
                i--;
            }
            else if(preorder[i] == ',') i--;
            else if(isdigit(preorder[i])){
                while(i>=0 && isdigit(preorder[i])) i--;
                cnter -= 1; // 去掉两个空叶节点，将当前这个非叶节点替换为空叶节点(+2, -1)
                if(cnter < 1) return false; // 若替换了却不存在空叶节点，则错误
            }
        }
        return cnter == 1; // 最后要求是剩下一个空的叶节点
    }
};