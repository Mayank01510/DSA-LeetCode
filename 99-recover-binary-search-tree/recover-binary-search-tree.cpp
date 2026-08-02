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
class Solution {
public:

    void inorder(TreeNode* root , vector<int>& in){
        if(root == NULL)return ;

        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }

    void recover(TreeNode* root , vector<int>& in,int &i){
        if(root == NULL)return;
        recover(root->left , in , i);
        if(root->val == in[i])i++;
        else {
            root->val = in[i];
            i++;
        }
        recover(root->right, in , i);
    }

    void recoverTree(TreeNode* root) {
        vector<int>in;
        inorder(root , in);
        sort(in.begin(),in.end());

        int i= 0;
        recover(root,in,i);
    }
};