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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxi=INT_MIN,ans=-1,level=0;
        if(root==NULL) return 0;
        while(!q.empty()){
            int size=q.size();
            int sum=0;
            level++;
            for(int i=0;i<size;i++){
                
                TreeNode* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                sum+=node->val;
            }
        
            if(sum>maxi){
                ans=level;
                maxi=sum;
            }
    
        }
        return ans;
    }
};