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
    void fun(TreeNode* root,int sum){
        if(!root->left && !root->right){
            ans+=sum;
            return ;
        }
        int temp;
        if(root->left){
            temp = (sum*10)+root->left->val;
            fun(root->left,temp);
        }
        if(root->right){
            temp=(sum*10)+root->right->val;
            fun(root->right,temp);
        }
        return ;
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        fun(root,root->val);
        return ans;
    }
};