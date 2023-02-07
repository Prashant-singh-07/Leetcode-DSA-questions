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
    unordered_map<int,int> m,l,r;
     int height(TreeNode* root){
         if(!root) return 0;
         int left=0,right=0;
          left=height(root->left);
         right=height(root->right);
         l[root->val] = left;
         r[root->val] = right;
         return 1+max(left,right);
     }
    void fun(TreeNode* root,int maxsofar,int depth){
        if(!root) return ;
        m[root->val]=maxsofar;
        
        fun(root->left,max(maxsofar,depth+r[root->val]),depth+1);
        fun(root->right,max(maxsofar,depth+l[root->val]),depth+1);
        
        
    }
    
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        height(root);
        fun(root->left,r[root->val],1);
        fun(root->right,l[root->val],1);
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(m[queries[i]]);
        }
        return ans;
            
    }
};