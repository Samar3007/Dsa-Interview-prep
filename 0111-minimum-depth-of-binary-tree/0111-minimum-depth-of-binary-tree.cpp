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
    int lvlTrav(TreeNode* root){
        if(!root) return 0;
        int level=1;
        queue<pair<TreeNode*,int>> q;
        q.push({root,level});
        
        while(!q.empty()){
            int size=q.size();
            level++;
            for(int i=0;i<size;size--){
                auto node=q.front();
                q.pop();
                if(node.first->left) q.push({node.first->left,level});
                if(node.first->right) q.push({node.first->right,level});
                if(!node.first->left && !node.first->right) return node.second;
            }
            
        }
        return level;
    }
        
    
    
    int minDepth(TreeNode* root) {
        return lvlTrav(root);
    }
};