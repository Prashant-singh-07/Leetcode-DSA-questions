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
    unordered_map<int,int> m;
    TreeNode* fun(vector<int>& postorder,int start,int end,int is,int ie){
        if(start>end) return NULL;
        TreeNode* root = new TreeNode(postorder[end]);
        int ind = m[postorder[end]];
        int r = ie-ind;
        int l = ind-is;
        if(r>0)
        root->right = fun(postorder,end-r,end-1,ind+1,ie);
        root->left = fun(postorder,start,end-r-1,is,ind-1);
            
       return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        int n = postorder.size();
        return fun(postorder,0,n-1,0,n-1);
        
    }
};