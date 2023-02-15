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
    int ans=0;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
         if(left==1 || right==1) {
            ans++;
            return 2;
        }
        else if(left==0 && right==0) return 1;
       
        else if(left==2 || right==2){
            return 0;
        }
         return 0;
    }
    
    int minCameraCover(TreeNode* root) {
        int k = dfs(root);
        if(k==1) ans++;
        return ans;
    }
};