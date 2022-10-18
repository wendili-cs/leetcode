// https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
private:
    
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string s;
        function<void(Node*)> dfs_encode;
        dfs_encode = [&](Node* node) -> void {
            if(!node) return;
            s += " " + to_string(node->val) + " " + to_string(node->children.size());
            for(Node *c:node->children){
                dfs_encode(c);
            }
        };
        dfs_encode(root);
        return s;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        stringstream ss(data);
        function<Node*()> dfs_decode;
        dfs_decode = [&]() -> Node* {
            int val, csize;
            if(ss >> val >> csize){
                Node* root = new Node(val);
                for(int i = 0; i < csize; i++){
                    root->children.push_back(dfs_decode());
                }
                return root;
            }
            return nullptr;
        };
        return dfs_decode();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));