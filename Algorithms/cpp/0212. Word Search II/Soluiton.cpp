// https://leetcode-cn.com/problems/word-search-ii/

class PrefixTreeNode{
public:
    unordered_map<char, PrefixTreeNode*> children;
    string word; // 单词存这里
    PrefixTreeNode() {}
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        PrefixTreeNode* root = new PrefixTreeNode();
        for(string& word:words){
            PrefixTreeNode* node = root;
            for(char& c:word){
                if(node->children.find(c) == node->children.end())
                    node->children[c] = new PrefixTreeNode();
                node = node->children[c];
            }
            node->word = word;
        }
        int m = board.size(), n = board[0].size();
        vector<string> res;
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        function<void(int, int, PrefixTreeNode*)> backtrace;
        backtrace = [&](int x, int y, PrefixTreeNode* parent){
            PrefixTreeNode* node = parent->children[board[x][y]];
            if(!node->word.empty()){ // 找到了单词，把它放到答案里面
                res.push_back(node->word);
                node->word = "";
            }
            visited[x][y] = true;
            if(x > 0 && !visited[x - 1][y] && node->children.find(board[x - 1][y]) != node->children.end())
                backtrace(x - 1, y, node);
            if(x < m - 1 && !visited[x + 1][y] && node->children.find(board[x + 1][y]) != node->children.end())
                backtrace(x + 1, y, node);
            if(y > 0 && !visited[x][y - 1] && node->children.find(board[x][y - 1]) != node->children.end())
                backtrace(x, y - 1, node);
            if(y < n - 1 && !visited[x][y + 1] && node->children.find(board[x][y + 1]) != node->children.end())
                backtrace(x, y + 1, node);
            visited[x][y] = false;
            if(node->children.empty()) parent->children.erase(board[x][y]); // 若是叶子节点，卸磨杀驴
        };
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(root->children.find(board[i][j]) != root->children.end())
                    backtrace(i, j, root);
            }
        }
        return res;
    }
};