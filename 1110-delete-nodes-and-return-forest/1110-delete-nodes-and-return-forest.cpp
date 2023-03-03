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
    vector<TreeNode*> ans;
    unordered_map<int,int> m;
    void fun(TreeNode* root){
        if(!root) return ;
        if(m.find(root->val)!=m.end()) root->val=-1;
        fun(root->left);
        fun(root->right);
    }
    void forest(TreeNode* root){
        if(!root) return ;
        forest(root->left);
        forest(root->right);
        if(root->val==-1){
            if(root->left && root->left->val!=-1) ans.push_back(root->left);
            if(root->right && root->right->val!=-1) ans.push_back(root->right);
           
        }
        if(root->left && root->left->val==-1) root->left= NULL;
        if(root->right && root->right->val==-1) root->right= NULL;
        
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i=0;i<to_delete.size();i++){
            m[to_delete[i]]++;
        }
        fun(root);
        forest(root);
        if(root->val!=-1) ans.push_back(root);
        return ans;
    }
};