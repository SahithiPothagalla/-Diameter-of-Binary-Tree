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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        int diameterThroughRoot = leftHeight + rightHeight;
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
        return max(diameterThroughRoot, max(leftDiameter, rightDiameter));
    }
    int getHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        return max(leftHeight, rightHeight) + 1;
    }
};
