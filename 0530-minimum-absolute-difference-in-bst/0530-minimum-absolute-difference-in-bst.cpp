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

    int trav(TreeNode* root, int& val, int& min_diff){
        if(root->left){
            trav(root->left,val,min_diff);
        }
        if(val>=0){
            min_diff=min(min_diff,root->val-val);
        }
        
        val=root->val;
        
        if(root->right){
            trav(root->right,val,min_diff);
        }
        
        return min_diff;

    }
    
    
    int getMinimumDifference(TreeNode* root) {
        int val=-1,min_diff=INT_MAX;
        return trav(root,val,min_diff);
    }
};