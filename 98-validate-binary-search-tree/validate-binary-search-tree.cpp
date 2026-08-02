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

    void inorder(TreeNode* root , int &valid ,long maxi,long mini){
        if(root == NULL || valid == -1)return ;

        if(root->val >= maxi || root->val <= mini){
            valid = -1;
            return;
        }

        inorder(root->left,valid,root->val,mini);
        inorder(root->right,valid,maxi,root->val);
    }

    bool isValidBST(TreeNode* root) {
        int valid = 0 ;

        inorder(root,valid,LONG_MAX,LONG_MIN);

        return valid == 0;
    }
};