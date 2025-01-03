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
    bool preorder(TreeNode* node, int currSum, int &targetSum) {
        if (node == nullptr) {
            return false;
        }
        currSum += node->val;
        if (node->left == nullptr && node->right == nullptr) {
            if (currSum == targetSum)
                return true;
        }
        return preorder(node->left, currSum, targetSum) ||
        preorder(node->right, currSum, targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return preorder(root, 0, targetSum);
    }
};
