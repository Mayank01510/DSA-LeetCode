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

    void inorder(TreeNode* root ,TreeNode* &prev , TreeNode* &first , TreeNode* &second ){
        if(root == NULL)return ;

        inorder(root->left,prev,first,second);

        if(prev != NULL && root->val < prev->val){
          if(first == nullptr)  first = prev ;
            second = root ; 
        }
        prev = root ;

        inorder(root->right,prev,first,second);
    }

   

    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        TreeNode* prev = NULL;
        inorder(root , prev,first,second);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};