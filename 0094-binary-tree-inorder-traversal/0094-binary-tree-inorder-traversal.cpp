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
 /*vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(root){
            if(root->left){ 
                ans.push_back(root->left->val);
                inorderTraversal(root->left);
            }
            else{
                ans.push_back(root->val);
                if(root->right){
                    inorderTraversal(root->right);
                }
            }
        }
        return ans;
    }
};
*/
vector<int> ans;
vector<int> inorderTraversal(TreeNode* root) {
    traversal(root);
    return ans;
}
void traversal(TreeNode* root){
        if(root==NULL) return;
            
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right); 
}
};