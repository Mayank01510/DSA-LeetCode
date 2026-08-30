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

    void pre(TreeNode* root, int targetSum , int &sum , int &flag){
        sum += root->val;
        if(root == nullptr || (root->left==NULL && root->right==NULL)){
            if(sum == targetSum) flag = 1; 

            sum -= root->val;
            return ;
        }

            if(root->left)pre(root->left , targetSum , sum ,flag);
            if(flag == 1)return;

            

            if(root->right)pre(root->right , targetSum , sum ,flag);
            if(flag == 1)return;

            sum -= root->val;
            
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)return 0;
        int sum = 0;
        int flag = 0;
        pre(root, targetSum , sum , flag);
        if(flag == 1)return true;
        return false;
    }
};