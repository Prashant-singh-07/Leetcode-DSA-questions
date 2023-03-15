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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return root;
        if(root->val>=low && root->val<= high){
            if(root->left)root->left =  trimBST(root->left,low,high);
            if(root->right) root->right = trimBST(root->right,low,high);
        }
        else{
             TreeNode* p = NULL;
            if(root->val<low){
                if(root->right){
                  p  = trimBST(root->right,low,high);
                    
                }
            }
            else if(root->val>high){
                if(root->left) p =  trimBST(root->left,low,high);
            }
            return p;
        }
        return root;
    }
};