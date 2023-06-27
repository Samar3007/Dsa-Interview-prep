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
    int count=0;
    
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        return func(root, root->val);
    }
    
    int func(TreeNode* root,int maxi){
        if(!root) return 0;
        if(root->val>=maxi){
            maxi=root->val;
            count++;
        }
        func(root->left,maxi);
        func(root->right,maxi);
        
        return count;
    }
    
    
};