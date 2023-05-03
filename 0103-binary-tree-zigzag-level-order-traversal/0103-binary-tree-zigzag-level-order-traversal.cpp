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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode* > Q;
        bool left2right=true;
        Q.push(root);
        while(!Q.empty()){
            int size=Q.size();
            vector<int> vec(size);
            for(int i=0;i<size;i++){
                TreeNode* node=Q.front();
                Q.pop();
                
                int index=left2right ? i : size-1-i;
                vec[index]=node->val;
                if(node->left) Q.push(node->left);
                if(node->right) Q.push(node->right);
            }
            left2right=!left2right;
            ans.push_back(vec);
        }
        return ans;
    }
};