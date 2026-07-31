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
private:
    stack<TreeNode*>mystack ; 
    bool reverse = true ;
public:

    void store(TreeNode* node){
        while(node != NULL){
            mystack.push(node);
            if(reverse)node = node->right;
            else node = node->left;
        }
    }

    BSTIterator(TreeNode* root , bool isreverse){
        reverse = isreverse ;
        store(root);
    }
    
    int next() {
        TreeNode* temp = mystack.top();
        mystack.pop();
        if(!reverse)store(temp->right);
        else store(temp->left);
        return temp->val;
    }
    
    bool hasNext() {
        return !mystack.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if( !root )return false;

        BSTIterator l (root , false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();

        while(i<j){
        if(i+j == k)return true;
        if(i+j<k) i = l.next();
        else j = r.next();
        }
        return false;
    }
};