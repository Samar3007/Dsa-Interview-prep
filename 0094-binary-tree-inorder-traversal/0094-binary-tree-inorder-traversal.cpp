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
    std::vector<int> inOrderTraversal;
    vector<int> inorderTraversal(TreeNode* root) {
        traversal(root);
        return this->inOrderTraversal;
    }
    void traversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        inorderTraversal(root->left);
        inOrderTraversal.push_back(root->val);
        inorderTraversal(root->right);
    }
};
