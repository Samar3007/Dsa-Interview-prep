/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parent){
        if(!node) return;
        if(node->left){
            parent[node->left]=node;
            markParent(node->left, parent);
        }
        if(node->right){
            parent[node->right]=node;
            markParent(node->right, parent);
        }
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*, TreeNode*> parent;
        markParent(root, parent);
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=true;
        int level=0;
        while(!q.empty()){
            int size=q.size();
            if(level==k) break;
            level++;
            for(int i=0;i<size;i++){
                auto node=q.front();
                q.pop();
                
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left]=true;
                }
                
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right]=true;
                }
                
                if(parent[node] && !vis[parent[node]]){
                    q.push(parent[node]);
                    vis[parent[node]]=true;
                }
            }
        }
        
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;

    }
};