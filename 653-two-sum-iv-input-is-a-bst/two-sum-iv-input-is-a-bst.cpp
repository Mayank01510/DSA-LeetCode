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

    void inorder(TreeNode* root , map<int,int>& mpp){
        if(root == NULL)return ;

        inorder(root->left,mpp);
        mpp[root->val]++;
        inorder(root->right,mpp);
    }

    bool findTarget(TreeNode* root, int k) {
        map<int,int>mpp;

        inorder(root,mpp);

        for(auto [first,second] : mpp){
            mpp[first]--;
            if(mpp[first] == 0)mpp.erase(first);
            if(mpp.find(k-first) != mpp.end()) return true;
        }
        return false;
    }
};