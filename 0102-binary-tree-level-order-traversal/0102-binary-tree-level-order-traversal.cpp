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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*,int>> bot;
        vector<vector<int>> res;
        if(!root) return res;
        bot.push({root,0});
        while(!bot.empty()){
            int size=bot.size();
            int level=bot.front().second;
            vector<int> ans;
            for(int i=0;i<size;i++){
                TreeNode* node=bot.front().first;
                ans.push_back(node->val);
                bot.pop();
                if(node->left){
                    bot.push({node->left,level+1});
                }
                if(node->right){
                    bot.push({node->right,level+1});
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};