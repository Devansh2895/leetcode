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
    void preorder(TreeNode* node, int currSum, int &targetSum,
                    vector<int> &sum, vector<vector<int>> &result) {
        if (node == nullptr) {
            return;
        }
        currSum += node->val;
        sum.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            if (currSum == targetSum)
                    result.push_back(sum);
        }
        preorder(node->left, currSum, targetSum, sum, result);
        preorder(node->right, currSum, targetSum, sum, result);
        sum.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> sum;
        preorder(root, 0, targetSum, sum, result);

        return result;
    }
};
