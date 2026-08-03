class Solution {
public:

    struct Info {
        bool isBST;
        long minVal;
        long maxVal;
        long sum;
    };

    Info solve(TreeNode* root, long &ans) {

        if (root == NULL) {
            return {true, LONG_MAX, LONG_MIN, 0};
        }

        Info left = solve(root->left, ans);
        Info right = solve(root->right, ans);

        // Check if current subtree is BST
        if (left.isBST && right.isBST &&
            left.maxVal < root->val &&
            root->val < right.minVal) {

            long currSum = left.sum + right.sum + root->val;

            ans = max(ans, currSum);

            return {
                true,
                min((long)root->val, left.minVal),
                max((long)root->val, right.maxVal),
                currSum
            };
        }

        // Current subtree is not BST
        return {
            false,
            LONG_MIN,
            LONG_MAX,
            0
        };
    }

    int maxSumBST(TreeNode* root) {
        long ans = 0;

        solve(root, ans);

        return ans;
    }
};