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
    int ind=0;
    vector<int> ans;
    void fun(TreeNode* root,vector<int>& v){
        if(!root || (ans.size() && ans[0]==-1)) return ;
        
        if(root->val!=v[ind++]){
            ans={-1};
            return ;
        }
        if(root->left && root->left->val!=v[ind]){
            ans.push_back(root->val);
            fun(root->right,v);
            fun(root->left,v);
        }
        else{
             fun(root->left,v);
            fun(root->right,v);
        }
        return ;
        
    }
    
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        //preorder list is given, so firstly learn how to traverse through tree using preorder list.
        
        fun(root,voyage);
        return ans;
        
    }
};