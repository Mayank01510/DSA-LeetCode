/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    private :
    int i = 0;
    vector<int> in;
public:

    void inorder(TreeNode* root,vector<int> & in){
        if(root == NULL)return;

        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }

    BSTIterator(TreeNode* root) {
        inorder(root,in);
    }
    
    int next() {
        return in[i++];
        
    }
    
    bool hasNext() {
        if(i<in.size())return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */