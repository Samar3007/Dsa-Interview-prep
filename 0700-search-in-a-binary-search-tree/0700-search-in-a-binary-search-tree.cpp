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
    TreeNode* ans=NULL;
    TreeNode* trav(TreeNode* root, int val){
        if(root->val==val) ans=root; 
        if(root->left) trav(root->left,val);
        if(root->right) trav(root->right,val);
        if(ans!=NULL) return ans;
        return NULL;
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* tree=trav(root,val);
        return tree;
    }
};