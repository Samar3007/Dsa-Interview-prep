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
    TreeNode* searchBST(TreeNode* root, int val){
        if(root->val==val) ans=root; 
        if(root->left){
            if(ans!=NULL) return ans;
            searchBST(root->left,val);
            
        }
        if(root->right){
            if(ans!=NULL) return ans;
            searchBST(root->right,val);
            
        }
        if(ans!=NULL) return ans;
        return NULL;
    }
    
};