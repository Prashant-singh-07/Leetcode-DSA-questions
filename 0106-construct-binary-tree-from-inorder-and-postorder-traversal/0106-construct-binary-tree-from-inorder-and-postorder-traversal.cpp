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
    TreeNode* fun(int start,int end,vector<int>& postorder){
        if(start>end){
            return NULL;
        }
        int k;
        for(int i=postorder.size()-1;i>=0;i--) if(m[postorder[i]]>=start && m[postorder[i]]<=end){
            k=i;
            break;
        }
        TreeNode* ans = new TreeNode(postorder[k]);
        if(start==end){
            return ans;
        }
        ans->left = fun(start,m[postorder[k]]-1,postorder);
        ans->right = fun(m[postorder[k]]+1,end,postorder);
        return ans;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

         int n = inorder.size();
        for(int i=0;i<n;i++) m[inorder[i]]=i;
       
        TreeNode* root = new TreeNode(postorder[n-1]);
        root->left = fun(0,m[postorder[n-1]]-1,postorder);
         root->right = fun(m[postorder[n-1]]+1,n-1,postorder);
         return root;
        
    }
};